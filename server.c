#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>

int main() {

    char msg[256] = "server reached";
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in s_addr;
    s_addr.sin_family = AF_INET;
    s_addr.sin_port = htons(8081);
    s_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    int b = bind(sock, (struct sockaddr *) &s_addr, sizeof(s_addr));

    int l = listen(sock, 5);

    while (1)
    {
	printf("wating for a client\n");
         
    int a = accept(sock, NULL, NULL);

    send(a, msg, sizeof(msg),0);
	printf("msg sent to %d\n",a);
    close(a);
    }
   
    close(sock);
    return 0;
}
