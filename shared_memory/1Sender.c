#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/mman.h>
#include<fcntl.h>
#include<stddef.h>
int main()
{   
    int num1;
    int fd = shm_open("/shm",O_CREAT|O_RDWR,0666);       //Create shared memory
    ftruncate(fd,2*sizeof(int));                         //setting size

    //map shared memory to address of process
    int *data = (int *)mmap(NULL,2*sizeof(int),PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    scanf("%d",&num1);
    data[0] = num1;
    munmap(data,2*sizeof(int));
    close(fd);
    return 0;


}