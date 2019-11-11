#include<stdio.h>
// /Users/jiteshsah/Desktop/OS/OS_CODE/Lab_assignment/wish
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main()
{
    int result=access("/bin/ls",F_OK);
    printf("Received result = %d ",result);
    return 0;

}