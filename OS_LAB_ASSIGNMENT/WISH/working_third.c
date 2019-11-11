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
char *found=NULL;
args[0]=(char *)malloc(sizeof(path));
args[1]=NULL;
// args[0]=strdup(path);
printf("The args is %s",args[0]);
args[0]=strdup("/bin/ls/\0");
printf("The args is %s",args[0]);
while(strcmp(command,"exit")!=0)
{
    // printf("0");
    printf("\nwish>");
    gets(command);
    
    // printf("\nPID is %d\n",pid);
    printf("\nCommand is %s\n",command);
    temp=strdup(command);
    printf("\nTemp Command is %s\n",temp);
    int pid=fork();
    if(pid==-1)
    {
        eprint();
    }
    else if(pid==0)
    {
        printf("CHILD ||");
        
        int i=0;
        printf("\nfound | %s\n",found);
        while((found=strsep(&temp," "))!=NULL)
        {
            printf("STARTED");
            printf("found is | %s ",found);
            args[i]=found;
            i++;
        }
        strcat(path,args[0]);
        args[0]=path;
        i=0;
        while(args[i]!=NULL)
        {
            printf("\nArgs[%d] is %s\n",i,args[i]);
            i++;
        }
        // printf("\nArgs[1] is %s\n",args[1]);
        // printf("\nArgs[2] is %s\n",args[2]);
        // printf(path);
        execv(args[0],args);
        i=0;
        while(args[i]!=NULL)
        {
            args[i]=NULL;
            i++;
            // args[1]=NULL;        
        }
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