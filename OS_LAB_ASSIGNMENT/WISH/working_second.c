#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
void eprint()
{
    char error_message[30] = "An error has occurred\n";
    write(STDERR_FILENO, error_message, strlen(error_message)); 
}
int main(){
printf("Welcome to WIscosin SHell");
char command[100];
char path[100]="/bin/";
char *args[100];
char *temp=NULL;
args[0]=(char *)malloc(sizeof(path));
args[1]=NULL;
args[0]=path;
printf("The args is %s",args[0]);
args[0]="/bin/ls/\0";
printf("The args is %s",args[0]);
while(strcmp(command,"exit")!=0)
{
    // printf("0");
    printf("\nwish>");
    scanf("%s",command);
    int pid=fork();
    // printf("\nPID is %d\n",pid);
    if(pid==-1)
    {
        eprint();
    }
    else if(pid==0)
    {
        printf("CHILD ||");
        // int pid=fork();
        temp=path;
        printf("\ntemp is %s\n",temp);
        strcat(path,command);
        args[0]=path;
        // path="/bin/"; //error: array type 'char [100]' is not assignable
        printf("\nArgs[0] is %s\n",args[0]);
        // printf(path);
        execv(args[0],args);
        
        exit(0);
    }
    else 
    {
        wait(NULL);
        printf("PARENT hu mei");
        
    }
}
// else
    // printf("Exiting");

return 1;
}