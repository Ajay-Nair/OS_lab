#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>

int main()
{

    struct stat buf;
    stat("./chk_dir.c",&buf);
    printf("%ld\n", buf.st_mode);

    return 0;
}