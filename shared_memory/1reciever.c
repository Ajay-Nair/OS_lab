#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/mman.h>
#include<fcntl.h>
#include<stddef.h>
int main()
{
    int fd = shm_open("/shm",O_RDWR,0666);       //Read shared memory
    ftruncate(fd,2*sizeof(int));                         //setting size

    //map shared memory to address of process
    int *data = (int *)mmap(NULL,2*sizeof(int),PROT_READ,MAP_SHARED,fd,0);
    int i, k;
    for (i = 1, k = 1; i < data[0]; i++, k *= i)
    {

    }
    printf("\nFactorial of %d is %d.\n", data[0], k);
     munmap(data, sizeof(int));

    // closing file descriptor
    close(fd);

    shm_unlink("/shm");

    return 0;
    
}