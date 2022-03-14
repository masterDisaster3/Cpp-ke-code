#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BACKLOG 5
#define BUFFERSIZE 255

void error(const char *msg){
	perror(msg);
	exit(1);
}

int main(int argc, char const *argv[])
{
	if(argc != 2){
		fprintf(stderr, "Usage: server portNumber\n");
		exit(1);
	}


	int sockfd, newsockfd, portNumber, n;
	char buffer[BUFFERSIZE];

	portNumber = atoi(argv[1]);

	struct sockaddr_in serverinfo, clientinfo;
	socklen_t client_len;

	memset(&serverinfo, 0, sizeof serverinfo);

	serverinfo.sin_family = AF_INET;
	serverinfo.sin_addr.s_addr = htonl(INADDR_ANY);
	serverinfo.sin_port = htons(portNumber);


	sockfd = socket(AF_INET, SOCK_STREAM,0);
	if(sockfd < 0)
		error("socket me dikkat aari🥺\n");


	if(bind(sockfd, (struct sockaddr *) &serverinfo, sizeof serverinfo) < 0)
		error("binding me dikkat aari🥺\n");

	listen(sockfd, BACKLOG);
	client_len = sizeof clientinfo;

	newsockfd = accept(sockfd, (struct sockaddr *) &clientinfo, &client_len);

	if(newsockfd < 0)
		error("client me dikkat aari🥺\n");

	memset(&buffer, 0, sizeof buffer);

	while(1){
		n = read(newsockfd, buffer, BUFFERSIZE);
		if(n < 0)
			error("read nahi ho paara🥺\n");
		printf("Client: %s\n", buffer);
		memset(&buffer, 0, sizeof buffer);
		fgets(buffer, BUFFERSIZE, stdin);

		n = write(newsockfd, buffer, strlen(buffer));
		if(n < 0)
			error("write nahi ho paara🥺\n");

		int i = strncmp("bye", buffer,3);
		if(i == 0)
			break;
	}

	close(newsockfd);
	close(sockfd);
	exit(1);
	return 0;
}