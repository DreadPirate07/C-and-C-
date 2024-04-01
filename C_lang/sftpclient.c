#include <libssh/libssh.h>
#include <libssh/sftp.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#define MAX_XFER_BUF_SIZE 16384

int do_sftp(ssh_session session)
{
    sftp_session sftp;
    int access_type = O_WRONLY | O_CREAT | O_TRUNC;
    sftp_file file;
    const char *helloworld = "Hello, World!\n";
    int length = strlen(helloworld);
    int rc, nwritten;
    char buffer[MAX_XFER_BUF_SIZE];
    int nbytes;
    int fd;
    sftp_dir dir;
    sftp_attributes attributes;

    // sftp init
    sftp = sftp_new(session);
    if (sftp == NULL)
    {
        fprintf(stderr, "Error allocating SFTP session: %s\n",
                ssh_get_error(session));
        return SSH_ERROR;
    }
    else
        printf("successful sftp_new \n");

    rc = sftp_init(sftp);
    if (rc != SSH_OK)
    {
        fprintf(stderr, "Error initializing SFTP session: code %d.\n",
                sftp_get_error(sftp));
        sftp_free(sftp);
        return rc;
    }
    else
        printf("successful sftp_init \n");

    // sftp mkdir
    rc = sftp_mkdir(sftp, "helloworld", S_IRWXU);
    if (rc != SSH_OK)
    {
        if (sftp_get_error(sftp) != SSH_FX_FILE_ALREADY_EXISTS)
        {
            fprintf(stderr, "Can't create directory: %s\n",
                    ssh_get_error(session));
            return rc;
        }
    }

    // Copying a file to remote computer
    file = sftp_open(sftp, "helloworld/helloworld.txt",
                     access_type, S_IRWXU);
    if (file == NULL)
    {
        fprintf(stderr, "Can't open file for writing: %s\n",
                ssh_get_error(session));
        return SSH_ERROR;
    }

    nwritten = sftp_write(file, helloworld, length);
    if (nwritten != length)
    {
        fprintf(stderr, "Can't write data to file: %s\n",
                ssh_get_error(session));
        sftp_close(file);
        return SSH_ERROR;
    }

    rc = sftp_close(file);
    if (rc != SSH_OK)
    {
        fprintf(stderr, "Can't close the written file: %s\n",
                ssh_get_error(session));
        return rc;
    }

    // Reading a file from computer...
    access_type = O_RDONLY;
    file = sftp_open(sftp, "/etc/profile",
                     access_type, 0);
    if (file == NULL)
    {
        fprintf(stderr, "Can't open file for reading: %s\n",
                ssh_get_error(session));
        return SSH_ERROR;
    }

    fd = open("./examples/helloworld", O_CREAT);
    if (fd < 0)
    {
        fprintf(stderr, "Can't open file for writing: %s\n",
                strerror(errno));
        return SSH_ERROR;
    }

    for (;;)
    {
        nbytes = sftp_read(file, buffer, sizeof(buffer));
        if (nbytes == 0)
        {
            break; // EOF
        }
        else if (nbytes < 0)
        {
            fprintf(stderr, "Error while reading file: %s\n",
                    ssh_get_error(session));
            sftp_close(file);
            return SSH_ERROR;
        }

        nwritten = write(fd, buffer, nbytes);
        if (nwritten != nbytes)
        {
            fprintf(stderr, "Error writing: %s\n",
                    strerror(errno));
            sftp_close(file);
            return SSH_ERROR;
        }
    }

    rc = sftp_close(file);
    if (rc != SSH_OK)
    {
        fprintf(stderr, "Can't close the read file: %s\n",
                ssh_get_error(session));
        return rc;
    }

    //Listing the contents of directory!
    dir = sftp_opendir(sftp, "/var/log");
    if (!dir)
    {
        fprintf(stderr, "Directory not opened: %s\n",
                ssh_get_error(session));
        return SSH_ERROR;
    }

    printf("Name                       Size Perms    Owner\tGroup\n");

    while ((attributes = sftp_readdir(sftp, dir)) != NULL)
    {
        printf("%-20s %10llu %.8o %s(%d)\t%s(%d)\n",
               attributes->name,
               (long long unsigned int)attributes->size,
               attributes->permissions,
               attributes->owner,
               attributes->uid,
               attributes->group,
               attributes->gid);

        sftp_attributes_free(attributes);
    }

    if (!sftp_dir_eof(dir))
    {
        fprintf(stderr, "Can't list directory: %s\n",
                ssh_get_error(session));
        sftp_closedir(dir);
        return SSH_ERROR;
    }

    rc = sftp_closedir(dir);
    if (rc != SSH_OK)
    {
        fprintf(stderr, "Can't close directory: %s\n",
                ssh_get_error(session));
        return rc;
    }

    sftp_free(sftp);
    return SSH_OK;
}

int main(int argc, char **argv)
{
    ssh_session session = NULL;
    sftp_session sftp = NULL;
    char *password = NULL;
    int rc;

    rc = ssh_init();
    session = ssh_new();
    if (session == NULL)
    {
        fprintf(stderr, "Error creating SSH session\n");
        return EXIT_FAILURE;
    }

    ssh_options_set(session, SSH_OPTIONS_HOST, "127.0.0.1");
    ssh_options_set(session, SSH_OPTIONS_PORT_STR, "22222");
    ssh_options_set(session, SSH_OPTIONS_CIPHERS_C_S, "none");
    ssh_options_set(session, SSH_OPTIONS_CIPHERS_S_C, "none");
    ssh_options_set(session, SSH_OPTIONS_HMAC_C_S, "none");
    ssh_options_set(session, SSH_OPTIONS_HMAC_S_C, "none");
    rc = ssh_connect(session);
    if (rc != SSH_OK)
    {
        fprintf(stderr, "Connection error: %s\n", ssh_get_error(session));
        ssh_free(session);
        return EXIT_FAILURE;
    }
    printf("Connected! Ok \n");

    rc = ssh_userauth_password(session, "myuser", "mypassword");
    if (rc != SSH_AUTH_SUCCESS)
    {
        fprintf(stderr, "Error authenticating with password: %s\n",
                ssh_get_error(session));
        ssh_disconnect(session);
        ssh_free(session);
        exit(-1);
    }
    else
    {
        printf("Authentication success using password! \n");
    }

    do_sftp(session);

    ssh_disconnect(session);
    ssh_free(session);

    ssh_finalize();

    return EXIT_SUCCESS;
}