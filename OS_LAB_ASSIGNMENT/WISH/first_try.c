#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>

int main(){
printf("Welcome to WIscosin SHell");
char command[100];
// printf("\nwish>");
// scanf("%s",&command);
// printf("about to print the entered command");
printf("The cmd is %s",command);
// printf(strcmp(command,"exit"));
while(strcmp(command,"exit")!=0)
{
    printf("0");
    printf("\nwish>");
    scanf("%s",command);
    int pid=fork();
    if(pid==-1)
    {
        printf("");
    }
    else if(pid==0)
    {
        printf("CHILD ||");
        // execv(command);
    }
    else 
    {
        wait(NULL);
        printf("PARENT ||");
        
    }
}
// else
    printf("Exiting");

return 1;
}