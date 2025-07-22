#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

void main()
{
pid_t pid;
pid=fork();
int retnice;
{
if(pid==0)
{
  retnice=nice(-6);
  printf("PID at higher priority %d \n",retnice);
  sleep(5);
}
else
{
  retnice=nice(6);
  printf("PID at lower pripority %d \n", retnice);
  sleep(5);
}
}
}
