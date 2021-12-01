#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char **argv){
	char buf[1024];
	int n;
	int in, out;

	in = open(argv[1], O_RDONLY);
	out = open(argv[2], O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
	
	while((n = read(in,buf,sizeof(buf)))>0) write(out,buf,n);

	return 0;
}
