#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/mman.h>
#include<sys/shm.h>
#include<string.h>
#include<stddef.h>
int main()
{
    int i;
    void *shared_memory;
    char buff[100];
    int shmid;
    shmid = shmget((key_t)2345,1024,0666|IPC_CREAT);
    printf("Key of shared memory is:%d\n",shmid);
    shared_memory = shmat(shmid,NULL,0);
    printf("Process attached at %p\n",shared_memory);
    printf("Enter data:\n");
    read(0,buff,100);
    strcpy(shared_memory,buff);
    printf("You wrote:%s \n",(char *)shared_memory);

}