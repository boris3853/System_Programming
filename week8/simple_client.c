#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ioctl.h>

#define SIZE(A) (sizeof(A) / sizeof(A[0]))

int main(int argc, char **argv){
	int fd;
	struct sockaddr_un address;
	int result;
	int len, nread;
	char input[10];

	fd = socket(AF_UNIX, SOCK_STREAM, 0);

	address.sun_family = AF_UNIX;
	strcpy(address.sun_path, "server_socket");
	len = sizeof(address);

	result = connect(fd, (struct sockaddr *)&address, len);
	
	if(result == -1){
		perror("connection failed");
		exit(1);
	}

	strcpy(input, argv[1]);
	write(fd, input, SIZE(input));
	read(fd, input, SIZE(input));
	printf("message from server = %s\n", input);
	close(fd);
	exit(0);
}
