#include <sys/types.h>
#include <sys/fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define SERVER_PORT 12345
#define BUFFER_SIZE 4096
#define QUEUE_SIZE 10



int main(int argc, char *argv[]){

    int soc_ket, bin_d, list_en, fd, sa, bytes, on = 1;
    char buf[BUFFER_SIZE];
    struct sockaddr_in channel;

    memset(&channel, 0, sizeof(channel));

    channel.sin_family = AF_INET;
    channel.sin_addr.s_addr = htonl(INADDR_ANY);
    channel.sin_port = htons(SERVER_PORT);

    soc_ket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(soc_ket < 0) fatal("Socket failed\n");

    setsockopt(soc_ket, SOL_SOCKET, SO_REUSEADDR, (char *)&on, sizeof(on));

    bin_d = bind(soc_ket,(struct sockaddr *) &channel, sizeof(channel));
    if(bin_d < 0) fatal("Bind failed\n");

    list_en = listen(soc_ket, QUEUE_SIZE);
    if(list_en < 0) fatal("Listen failed\n");

    while(1){
        sa = accept(soc_ket, 0 ,0);
        if(sa < 0) fatal("Accepted failed\n");

        read(sa , buf, BUFFER_SIZE);

        fd = open(buf, O_RDONLY);
        if(fd < 0) fatal("Open failed\n");

        while(1){
            bytes = read(fd, buf, BUFFER_SIZE);
            if(bytes <= 0) break;
            write(sa, buf, bytes);
        }

        close(fd);
        close(sa);
    }
    return 0;
}