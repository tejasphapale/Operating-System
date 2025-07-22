#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
int pid=fork();
if (pid>0){
printf("parent process creted \n");
printf("ID : %d\n",getpid());
}
else if (pid==0){
printf("child process...\n");
printf("ID: %d\n",getpid());

printf("parent id:%d \n",getppid());
sleep(5);
printf("child ID:%d\n",getpid());
}
else{
printf("failed to create process... \n");
}
return 0;
}
