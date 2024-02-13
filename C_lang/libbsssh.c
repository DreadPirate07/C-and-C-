#define LIBSSH_STATIC 1
#include <libssh/libssh.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    ssh_session my_ssh_session = ssh_new();
    int rc = 0;
    if (my_ssh_session == NULL)
        exit(1);
    else
        printf("new ssh created successfully \n");

    ssh_options_set(my_ssh_session, SSH_OPTIONS_HOST, "root@127.0.0.1");
    rc = ssh_connect(my_ssh_session);
    if (rc == SSH_OK)
        printf("Successfully connected \n");
    else
    {
        printf("Error Connecting to server - %s \n", ssh_get_error(my_ssh_session));

        exit(-1);
    }
    ssh_disconnect(my_ssh_session);
    ssh_free(my_ssh_session);
    return 0;
}