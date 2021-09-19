#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
    pid_t process;
    process = fork();
    fork();
    fork();
    fork();
    printf("Hello");
}