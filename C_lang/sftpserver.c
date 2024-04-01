#include <sys/wait.h>
#include <sys/stat.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <libssh/callbacks.h>
#include <libssh/server.h>
#include <libssh/sftp.h>
#include <libssh/sftpserver.h>
#include <argp.h>
#include <libssh/libssh.h>

const char USER[] = "myuser";
const char PASS[] = "mypassword";
const char HOST_KEY_FILE[] = "/tmp/hostkey";

static int
authenticate_user(ssh_session session)
{
    ssh_message message;
    do
    {
        message = ssh_message_get(session);
        if (message == NULL)
        {
            break;
        }

        if (ssh_message_type(message) == SSH_REQUEST_AUTH &&
            ssh_message_subtype(message) == SSH_AUTH_METHOD_PASSWORD)
        {
            if (strcmp(ssh_message_auth_user(message), USER) == 0 &&
                strcmp(ssh_message_auth_password(message), (char *)PASS) == 0)
            {
                ssh_message_auth_reply_success(message, 0);
                ssh_message_free(message);
                return 1; // Authentication succeeded
            }
        }
        ssh_message_reply_default(message);
        ssh_message_free(message);
    } while (message);
    return 0; // Authentication failed
}

static void handle_sftp_session(ssh_session session)
{
    if (!authenticate_user(session))
    {
        fprintf(stderr, "Authentication failed\n");
        return;
    }

    sftp_session sftp = sftp_new(session);
    if (sftp == NULL)
    {
        fprintf(stderr, "Error initializing SFTP session: %s\n", ssh_get_error(session));
        return;
    }

    if (sftp_init(sftp) != SSH_OK)
    {
        fprintf(stderr, "Error initializing SFTP session: %s\n", ssh_get_error(session));
        sftp_free(sftp);
        return;
    }

    // Handle SFTP operations

    sftp_free(sftp);
}

int main()
{
    ssh_bind sshbind = ssh_bind_new();
    ssh_session session;

    ssh_bind_options_set(sshbind, SSH_BIND_OPTIONS_BINDPORT_STR, "22222");
    ssh_bind_options_set(sshbind, SSH_BIND_OPTIONS_HOSTKEY, HOST_KEY_FILE);
    ssh_bind_options_set(sshbind, SSH_BIND_OPTIONS_BINDADDR, "127.0.0.1");
    ssh_bind_options_set(sshbind, SSH_BIND_OPTIONS_CIPHERS_C_S, "none");
    ssh_bind_options_set(sshbind, SSH_BIND_OPTIONS_CIPHERS_S_C, "none");
    ssh_bind_options_set(sshbind, SSH_BIND_OPTIONS_HMAC_C_S, "none");
    ssh_bind_options_set(sshbind, SSH_BIND_OPTIONS_HMAC_S_C, "none");

    if (ssh_bind_listen(sshbind) < 0)
    {
        fprintf(stderr, "Error listening to socket: %s\n", ssh_get_error(sshbind));
        return EXIT_FAILURE;
    }

    printf("SFTP Server listening on port %d\n", 22222);

    while (1)
    {
        session = ssh_new();
        if (session == NULL)
        {
            fprintf(stderr, "Failed to create session\n");
            continue;
        }

        if (ssh_bind_accept(sshbind, session) == SSH_OK)
        {
            if (ssh_handle_key_exchange(session))
            {
                fprintf(stderr, "Error in SSH key exchange: %s\n", ssh_get_error(session));
            }
            else
            {
                handle_sftp_session(session);
            }
        }
        else
        {
            fprintf(stderr, "Error accepting a connection: %s\n", ssh_get_error(sshbind));
        }
        ssh_disconnect(session);
        ssh_free(session);
    }

    ssh_bind_free(sshbind);
    ssh_finalize();
    return EXIT_SUCCESS;
}
