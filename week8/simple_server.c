#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdlib.h>

#define SIZE(a) (sizeof(a)/sizeof(a[0]))

int main(){
	int server_fd, client_fd;
	int server_len, client_len;
	struct sockaddr_un server_address;
	struct sockaddr_un client_address;
	char input[10];

	unlink("server_socket");
	server_fd = socket(AF_UNIX, SOCK_STREAM, 0);
	
	server_address.sun_family = AF_UNIX;
	strcpy(server_address.sun_path, "server_socket");
	server_len = sizeof(server_address);
	bind(server_fd, (struct sockaddr *)&server_address, server_len);

	listen(server_fd, 5);

	while(1){
		printf("server waiting\n");
		
		client_len = sizeof(client_address);
		client_fd = accept(server_fd, (struct sockaddr *)&client_address, &client_len);

		read(client_fd, &input, SIZE(input));
		strcat(input, ">>");
		write(client_fd, &input, SIZE(input));
		close(client_fd);
	}
}
	

