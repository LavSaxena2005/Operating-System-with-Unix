#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
int p = fork();
if (p > 0)
{printf("in parent process %d",p);
sleep(30);
}
else if (p == 0)
{
printf("in child process %d",p);
}
return 0;
}
