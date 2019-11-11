#include<stdio.h>
// /Users/jiteshsah/Desktop/OS/OS_CODE/Lab_assignment/wish
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
void eprint()
{
    char error_message[30] = "An error has occurred\n";
    write(STDERR_FILENO, error_message, strlen(error_message)); 
    main();
}
int main(){
    printf("Welcome to WIscosin SHell");
    char command[100];
    char tem[100];
    char path[100]="/bin/";
    char *args[100];
    char *temp=NULL;
    char *found=NULL;
    args[0]=(char *)malloc(sizeof(path));
    args[1]=NULL;
    // args[0]=strdup(path);
    // printf("The args is %s",args[0]);
    // args[0]=strdup("/bin/ls/\0");
    // printf("The args is %s",args[0]);
    while(strcmp(command,"exit")!=0)
    {
        // printf("0");
        
        printf("\nwish> ");
        gets(command);
        
        // printf("\nPID is %d\n",pid);
        printf("\nCommand is %s\n",command);
        temp=strdup(command);
        printf("\nTemp Command is %s\n",temp);


        int i=0;
        while(args[i]!=NULL)
        {
            args[i]=NULL;
            i++;
            // args[1]=NULL;        
        }
        i=0;
        printf("\nfound | %s\n",found);
        while((found=strsep(&temp," "))!=NULL)
        {
            printf("STARTED");
            printf("found is | %s ",found);
            args[i]=found;
            i++;
        }
        i=0;
        while(args[i]!=NULL)
        {
            strcpy(tem,args[i]);
            printf("\nstrcpy in tmp CD is %s\n",tem);
            if(strcmp(tem,"cd")==0)
            {
                printf("FOUND CD |");
                if(args[i+1]==NULL || args[i+2] != NULL )
                {
                    eprint();
                    exit(0);
                }
                else
                {
                    printf("Changing directory");
                    chdir(args[i+1]);
                    main();
                    exit(0);
                }
            }
            i++;
        }


        int pid=fork();
        if(pid==-1)
        {
            eprint();
        }
        else if(pid==0)
        {
            printf("CHILD ||");
            i=0;
            while(args[i]!=NULL)
            {
                printf("\nArgs[%d] is %s\n",i,args[i]);
                strcpy(tem,args[i]);
                printf("\nstrcpy in tmp is %s\n",tem);
                if(strcmp(tem,">")==0)
                {
                    args[i]=NULL;
                    printf("\nA MATCH\n");
                    temp=args[i+1];
                    printf("Filename is | %s",temp);
                    //Reference : https://stackoverflow.com/questions/2605130/redirecting-exec-output-to-a-buffer-or-file
                    int fd = open(temp,O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
                    dup2(fd, 1);   // make stdout go to file
                    dup2(fd, 2);   // make stderr go to file - you may choose to not do this
                    close(fd);     // fd no longer needed - the dup'ed handles are sufficient
                    strcat(path,args[0]);
                    args[0]=path;
                    execv(args[0],args);
                    
                    exit(0);
                }
                
                i++;
            }
            strcat(path,args[0]);
            args[0]=path;
            execv(args[0],args);
            i=0;
            // while(args[i]!=NULL)
            // {
            //     args[i]=NULL;
            //     i++;
            //     // args[1]=NULL;        
            // }
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