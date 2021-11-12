#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main(int argc, char **argv){
        pid_t pid[MAX];
        char* msg;
        int n = atoi(argv[1]);

        printf("fork() Test");
        for(int i=0;i<n;++i)
                pid[n] = fork();

        switch(pid[n]){
                case -1:
                        perror("fork failed");
                        exit(1);
                case 0:
                        msg = "This is child";
                        break;
                default:
                        msg = "This is parent";
                        break;
        }


        for(int i=0;i<10;++i){
                puts(msg);
                sleep(5);
        }

        return 0;
}

