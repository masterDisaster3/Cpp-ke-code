#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFERSIZE 255

void error(const char *msg){
	perror(msg);
	exit(1);
}

int main(int argc, char const *argv[])
{
	if(argc != 3){
		fprintf(stderr, "Usage: client ipAddress portNumber\n");
		exit(1);
	}

	int sockfd, portNumber, n;
	char buffer[BUFFERSIZE];
	struct hostent *server;
	struct sockaddr_in serverinfo;
	socklen_t client_len;

	server = gethostbyname(argv[1]);
	portNumber = atoi(argv[2]);

	sockfd = socket(AF_INET, SOCK_STREAM,0);
	if(server == NULL)
		fprintf(stderr,"Error, server not available of ipAddress is invalid!\n");


	memset(&serverinfo, 0, sizeof serverinfo);
	serverinfo.sin_family = AF_INET;
	bcopy((char *) server->h_addr, (char *) &serverinfo.sin_addr.s_addr, server->h_length);
	serverinfo.sin_port = htons(portNumber);

	if(connect(sockfd, (struct sockaddr *)&serverinfo, sizeof serverinfo) < 0)
		error("Connection failed!\n");

	while(1){
		memset(&buffer , 0, sizeof buffer);
		fgets(buffer, BUFFERSIZE, stdin);
		n = write(sockfd, buffer, strlen(buffer));

		if(n < 0)
			error("Writing error!\n");

		memset(&buffer , 0, sizeof buffer);
		n = read(sockfd, buffer, BUFFERSIZE);

		if(n < 0)
			error("Reading error!\n");

		printf("Server: %s\n", buffer);

		int i = strncmp("bye", buffer,3);
		if(i == 0)
			break;
	}
	
	close(sockfd);
	exit(1);
	return 0;
}