#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	int socketfd;
	int len;
	struct sockaddr_in address;
	int result;
	char ch = 0;

	socketfd = socket(AF_INET, SOCK_STREAM, 0);

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = inet_addr("127.0.0.1");
	address.sin_port = htons(9734);
	len = sizeof(address);

	result = connect(socketfd, (struct sockaddr *)&address, len);

	if(result = -1){
		perror("cannot connect");
		exit(1);
	}

	write(socketfd, &ch, 1);
	close(socketfd);
	exit(0);
}

