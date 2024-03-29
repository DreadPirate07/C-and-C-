#include <libssh/sftp.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#ifdef _WIN32
#define strncasecmp _strnicmp
#include <io.h>
#endif

int verify_knownhost(ssh_session session);

///////////////////////////////////////////////////////////////////////////////////////
// main
// SFTP client
///////////////////////////////////////////////////////////////////////////////////////

int main()
{
    ssh_session ssh_session;
    int verbosity = SSH_LOG_PROTOCOL;
    int port = 22;
    int rc;
    int i = 1;
    // If libssh is statically linked, threading must be initialized by calling ssh_init()
    // before using any of libssh provided functions. This initialization must be
    // done outside of any threading context.
    // Don't forget to call ssh_finalize() to avoid memory leak

    ssh_init();

    ssh_session = ssh_new();
    if (ssh_session == NULL)
    {
        printf("Session not found!");
        exit(-1);
    }

    ssh_options_set(ssh_session, SSH_OPTIONS_HOST, "192.168.1.152");
    ssh_options_set(ssh_session, SSH_OPTIONS_USER, "pvn");
    ssh_options_set(ssh_session, SSH_OPTIONS_KNOWNHOSTS, ".ssh/known_hosts");

    ssh_options_set(ssh_session, SSH_OPTIONS_PASSWORD_AUTH, &i);

    ssh_options_set(ssh_session, SSH_OPTIONS_LOG_VERBOSITY, &verbosity);
    ssh_options_set(ssh_session, SSH_OPTIONS_PORT, &port);

    rc = ssh_connect(ssh_session);
    if (rc != SSH_OK)
    {
        fprintf(stderr, "Error connecting to localhost: %s\n", ssh_get_error(ssh_session));
        exit(-1);
    }

    if (verify_knownhost(ssh_session) < 0)
    {
        fprintf(stderr, "Host not verified \n");
        ssh_disconnect(ssh_session);
        ssh_free(ssh_session);
        exit(-1);
    }

    rc = ssh_userauth_password(ssh_session, "user", "password");
    if (rc != SSH_AUTH_SUCCESS)
    {
        fprintf(stderr, "Error authenticating with password: %s\n",
                ssh_get_error(ssh_session));
    }

    ssh_disconnect(ssh_session);
    ssh_free(ssh_session);
    ssh_finalize();
}

///////////////////////////////////////////////////////////////////////////////////////
// verify_knownhost
///////////////////////////////////////////////////////////////////////////////////////

int verify_knownhost(ssh_session session)
{
    enum ssh_known_hosts_e state;
    unsigned char *hash = NULL;
    ssh_key srv_pubkey = NULL;
    size_t hlen;
    char buf[10];
    char *hexa;
    char *p;
    int cmp;
    int rc;

    rc = ssh_get_server_publickey(session, &srv_pubkey);
    if (rc < 0)
    {
        return -1;
    }

    rc = ssh_get_publickey_hash(srv_pubkey,
                                SSH_PUBLICKEY_HASH_SHA1,
                                &hash,
                                &hlen);
    ssh_key_free(srv_pubkey);
    if (rc < 0)
    {
        return -1;
    }

    state = ssh_session_is_known_server(session);
    switch (state)
    {
    case SSH_KNOWN_HOSTS_OK:
        /* OK */

        break;
    case SSH_KNOWN_HOSTS_CHANGED:
        fprintf(stderr, "Host key for server changed: it is now:\n");
        ssh_print_hexa("Public key hash", hash, hlen);
        fprintf(stderr, "For security reasons, connection will be stopped\n");
        ssh_clean_pubkey_hash(&hash);

        return -1;
    case SSH_KNOWN_HOSTS_OTHER:
        fprintf(stderr, "The host key for this server was not found but an other"
                        "type of key exists.\n");
        fprintf(stderr, "An attacker might change the default server key to"
                        "confuse your client into thinking the key does not exist\n");
        ssh_clean_pubkey_hash(&hash);

        return -1;
    case SSH_KNOWN_HOSTS_NOT_FOUND:
        fprintf(stderr, "Could not find known host file.\n");
        fprintf(stderr, "If you accept the host key here, the file will be"
                        "automatically created.\n");

        /* FALL THROUGH to SSH_SERVER_NOT_KNOWN behavior */

    case SSH_KNOWN_HOSTS_UNKNOWN:
        hexa = ssh_get_hexa(hash, hlen);
        fprintf(stderr, "The server is unknown. Do you trust the host key?\n");
        fprintf(stderr, "Public key hash: %s\n", hexa);
        ssh_string_free_char(hexa);
        ssh_clean_pubkey_hash(&hash);
        /*p = fgets(buf, sizeof(buf), stdin);
        if (p == NULL)
        {
          return -1;
        }

        cmp = strncasecmp(buf, "yes", 3);
        if (cmp != 0)
        {
          return -1;
        }
        */

        rc = ssh_session_update_known_hosts(session);
        if (rc < 0)
        {
            fprintf(stderr, "Error %s \n", hstrerror(errno));
            return -1;
        }

        break;
    case SSH_KNOWN_HOSTS_ERROR:
        fprintf(stderr, "Error %s", ssh_get_error(session));
        ssh_clean_pubkey_hash(&hash);
        return -1;
    }
    ssh_clean_pubkey_hash(&hash);
    return 0;
}
