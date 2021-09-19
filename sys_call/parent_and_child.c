#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
    pid_t process;
    process = fork();
    if (process<0)
    {
        printf("Child cannot be created/n");
    }
    if (process == 0)
    {
        printf("I am child \n");
    }
    else
    {
        printf("I am Parent \n");
    }

}