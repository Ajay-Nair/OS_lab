#include <stdio.h>
#include <sys/stat.h>

int main()
{

    struct stat buf;

    stat("./chk_dir.c", &buf);

    if (S_ISDIR(buf.st_mode))
    {
        printf("Directory exists!\n");
    }
    else
    {
        printf("Directory does'nt exist!\n");
    }

    return 0;
}