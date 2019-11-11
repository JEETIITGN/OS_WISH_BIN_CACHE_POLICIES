#include<stdio.h>
// /Users/jiteshsah/Desktop/OS/OS_CODE/Lab_assignment/wish
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
void eprint()
{
    char error_message[30] = "An error has occurred\n";
    write(STDERR_FILENO, error_message, strlen(error_message)); 
    // main();
}
char *all_path[10];
void shell()
{
    printf("Welcome to WIscosin SHell");
    char command[100];
    char tem[100];
    char path[100]="/bin/";
    char *args[100];
    char *temp=NULL;
    char *found=NULL;
    // args[0]=(char *)malloc(sizeof(path));
    // args[1]=NULL;
    int l=0;
    int j=0;
    int k=0;
    int flag=1;
    int back_to_while=0;
    // args[0]=strdup(path);
    // printf("The args is %s",args[0]);
    // args[0]=strdup("/bin/ls/\0");
    // printf("The args is %s",args[0]);
    while(strcmp(command,"exit")!=0)
    {
        // printf("WHILEEEEEEEEE");
        back_to_while=0;
        printf("\nwish> ");
        gets(command);
        
        // printf("\nPID is %d\n",pid);
        printf("\nCommand is %s\n",command);
        temp=strdup(command);
        printf("\nTemp Command is %s\n",temp);
        if(strcmp(command,"exit")==0)
        {
            exit(0);
        }
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
                printf("\nFOUND CD |");
                if(args[i+1]==NULL || args[i+2] != NULL )
                {
                    eprint();
                    shell();
                    exit(0);
                }
                else
                {
                    printf("\nChanging directory");
                    chdir(args[i+1]);
                    shell();
                    exit(0);
                }
            }
            else
            break;
            i++;
        }
        i=0;
        while(args[i]!=NULL)
        {
            strcpy(tem,args[i]);
            printf("\nstrcpy in tmp PATH is %s\n",tem);
            if(strcmp(tem,"path")==0)
            {
                printf("\nFOUND path |");
                j=i+1;
                while(args[j]!=NULL)
                {
                    printf("\nKuch toh hai path variable mei");
                    k=0;
                    while(all_path[k]!=NULL)
                    {
                        printf("\nThe value in all_path is %s |",all_path[k]);
                        k++;

                    }
                    all_path[k]=strdup(args[j]);
                    printf("The vlaue of all_path is %s ",all_path[k]);
                    j++;
                }
                printf("PATH SUCCESSFULLY ADDED TO THE PATH VARIABLE");
                back_to_while=1;
                break;
            }
            else
            break;
            i++;
        }
        if(back_to_while)
        continue;
        printf("\n\n\nCREATING FORK\n\n\n");
        int pid=fork();
        if(pid==-1)
        {
            eprint();
            shell();
        }
        else if(pid==0)
        {
            printf("\nCHILD ||");
            i=0;
            while(args[i]!=NULL)
            {
                
                printf("\nArgs[%d] is %s\n",i,args[i]);
                strcpy(tem,args[i]);
                printf("\nstrcpy in tmp is %s\n",tem);
                if(strcmp(tem,">")==0)
                {
                    args[i]=NULL;
                    printf("\nA MATCH PLUS filename is ");
                    temp=strdup(args[i+1]);
                    printf("Filename is | %s",temp);
                    //Reference : https://stackoverflow.com/questions/2605130/redirecting-exec-output-to-a-buffer-or-file
                    int fd = open(temp,O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
                    dup2(fd, 1);   // make stdout go to file
                    dup2(fd, 2);   // make stderr go to file - you may choose to not do this
                    close(fd);     // fd no longer needed - the dup'ed handles are sufficient
                    

                    k=0;
                    flag=1;
                    while(all_path[k]!=NULL)
                    {
                        printf("\nThe value in all_path is %s |",all_path[k]);
                        temp=strdup(all_path[k]);
                        strcat(temp,args[0]);
                        printf("TEMP | %s",temp);
                        int result=access(temp,F_OK);
                        printf("\nRESULT FINAL for concatenation in %d \n| ",result);
                        if(result==0)
                        {
                            printf("\n> The result is 0 with all_path as %s",all_path[k]);
                            args[0]=strdup(temp);
                            printf("\n> The value of args[1] is %s",args[1]);
                            printf("\n> The value is copied to args[0] is %s",args[0]);
                            execv(args[0],args);
                            exit(0);
                            flag=0;
                        }
                        else
                        {
                            printf("CHECKING IN THE NEXT PATH | ");
                        }

                        k++;

                    }
                    if(flag)//When the executable does not exist in any of the paths
                    {
                        eprint();
                        exit(1);
                    }


                    // strcat(path,args[0]);
                    // args[0]=path;
                    // execv(args[0],args);
                    
                    exit(0);
                }
                
                
                i++;
            }

            printf("\nEXEC ABOUT TO RUN IN WISCOSIN\n");
            k=0;
            flag=1;
            while(all_path[k]!=NULL)
            {
                printf("\nThe value in all_path is %s |",all_path[k]);
                temp=strdup(all_path[k]);
                strcat(temp,args[0]);
                printf("TEMP | %s",temp);
                int result=access(temp,F_OK);
                printf("\nRESULT FINAL %d \n| ",result);
                if(result==0)
                {
                    printf("The result is 0 with all_path as %s",all_path[k]);
                    args[0]=strdup(temp);
                    printf("The value is copied to args[0] is %s",args[0]);
                    execv(args[0],args);
                    exit(0);
                    flag=0;
                }
                else
                {
                    printf("CHECKING IN THE NEXT PATH | ");
                }

                k++;

            }
            if(flag)//When the executable does not exist in any of the paths
            {
                eprint();
                exit(1);
            }


            // strcat(path,args[0]);
            // args[0]=path;
            exit(0);
        }
        else 
        {
            wait(NULL);
            printf("\nPARENT hu mei");
            
        }
    }
    // else
        // printf("Exiting");


}








int main(int argc, char **argv){
    // all_path[0]=NULL;
    printf("The all_path is being set to NULL");

    for(int z=0;all_path[z]!=NULL;z++)
    {
        printf("\nThe value of all_path[%d] is %s",z,all_path[z]);
        all_path[z]=NULL;
    }
    // exit(0);
    char *command=(char *)malloc(1024);
    size_t size=1024;
    printf("\nThe 0 received is %s",argv[0]);
    printf("\nThe 1 received is %s",argv[1]);
    printf("\nThe 2 received is %s",argv[2]);

    if(argv[1] != NULL)
    {
        FILE *stream = fopen(argv[1],"r");
        if (stream==NULL)
        {
            printf("\nWISH CANNOT OPEN FILE");
            exit(1);
        }
        char tem[100];
        // char path[100]="/bin/";
        char *args[100];
        char *temp=NULL;
        char *found=NULL;
        // args[0]=(char *)malloc(sizeof(path));
        // args[1]=NULL;
        int l=0;
        int j=0;
        int k=0;
        int flag=1;
        int back_to_while=0;
        while(strcmp(command,"exit")!=0 && !feof(stream))
        {
            getline(&command,&size,stream);
            command=strtok(command,"\n");
            printf("\n%s",command);
            printf("\nWelcome to WIscosin BATCH SHell\n");
            // printf("0");
            back_to_while=0;
            
            // printf("\nPID is %d\n",pid);
            printf("\nCommand is %s\n",command);
            temp=strdup(command);
            printf("\nTemp Command is %s\n",temp);
            if(strcmp(command,"exit")==0)
            {
                exit(0);
            }
            // exit(0);
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
                    printf("\nFOUND CD |");
                    if(args[i+1]==NULL || args[i+2] != NULL )
                    {
                        eprint();
                        shell();
                        exit(0);
                    }
                    else
                    {
                        printf("\nChanging directory");
                        chdir(args[i+1]);
                        shell();
                        exit(0);
                    }
                }
                else
                break;
                i++;
            }
            i=0;
            while(args[i]!=NULL)
            {
                strcpy(tem,args[i]);
                printf("\nstrcpy in tmp PATH is %s\n",tem);
                if(strcmp(tem,"path")==0)
                {
                    printf("\nFOUND path |");
                    j=i+1;
                    int len=strlen(args[j]);
                    while(args[j]!=NULL)
                    {
                        printf("\nThe args of %d is %s",j,args[j]);
                        for(k=0;all_path[k]!=NULL;k++)
                        {
                            printf("\nAll_path is | %s",all_path[k]);
                        }
                        // exit(0);
                        printf("\nKuch toh hai path variable mei and its length is %d",len);
                        k=0;
                        while(all_path[k]!=NULL)
                        {
                            printf("\nLine 363:The value in all_path is %s and value of k is %d and j is %d and args[] is %s\n ",all_path[k],k,j,args[k]);
                            k++;
                            // if(k==3)
                            // exit(0);

                        }
                        // exit(0);
                        printf("The value of k is %d",k);
                        all_path[k]=strdup(args[j]);
                        printf("\nThe vlaue of all_path is %s ",all_path[k]);
                        // exit(0);
                        j++;
                        // if(j==4)
                        // exit(0);
                    }
                    printf("\nPATH SUCCESSFULLY ADDED TO THE PATH VARIABLE");
                    // exit(0);
                    back_to_while=1;
                    break;
                }
                else
                break;
                i++;
            }
            if(back_to_while)
            {
                continue;
            }
            printf("\n\n\nCREATING FORK\n\n\n");
            // exit(0);
            int pid=fork();
            if(pid==-1)
            {
                eprint();
                shell();
            }
            else if(pid==0)
            {
                printf("\nCHILD ||");
                
                i=0;
                while(args[i]!=NULL)
                {
                    
                    printf("\nArgs[%d] is %s\n",i,args[i]);
                    strcpy(tem,args[i]);
                    printf("\nstrcpy in tmp is %s\n",tem);
                    // exit(0);
                    if(strcmp(tem,">")==0)
                    {
                        args[i]=NULL;
                        printf("\nA MATCH PLUS filename is ");
                        temp=strdup(args[i+1]);
                        printf("Filename is | %s",temp);
                        //Reference : https://stackoverflow.com/questions/2605130/redirecting-exec-output-to-a-buffer-or-file
                        int fd = open(temp,O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
                        dup2(fd, 1);   // make stdout go to file
                        dup2(fd, 2);   // make stderr go to file - you may choose to not do this
                        close(fd);     // fd no longer needed - the dup'ed handles are sufficient
                        

                        k=0;
                        flag=1;
                        while(all_path[k]!=NULL)
                        {
                            printf("\nThe value in all_path is %s and in args[0] is %s ",all_path[k],args[0]);
                            temp=strdup(all_path[k]);
                            strcat(temp,args[0]);
                            printf("TEMP | %s",temp);
                            int result=access(temp,F_OK);
                            printf("\nRESULT FINAL for concatenation in %d \n| ",result);
                            if(result==0)
                            {
                                printf("\n> The result is 0 with all_path as %s",all_path[k]);
                                args[0]=strdup(temp);
                                printf("\n> The value of args[1] is %s",args[1]);
                                printf("\n> The value is copied to args[0] is %s",args[0]);
                                execv(args[0],args);
                                exit(0);
                                flag=0;
                            }
                            else
                            {
                                printf("CHECKING IN THE NEXT PATH | ");
                            }

                            k++;

                        }
                        if(flag)//When the executable does not exist in any of the paths
                        {
                            eprint();
                            exit(1);
                        }


                        // strcat(path,args[0]);
                        // args[0]=path;
                        // execv(args[0],args);
                        
                        exit(0);
                    }
                    
                    
                    i++;
                }

                printf("\nEXEC ABOUT TO RUN IN WISCOSIN\n");
                k=0;
                flag=1;
                while(all_path[k]!=NULL)
                {
                    printf("\nThe value in all_path is %s |",all_path[k]);
                    temp=strdup(all_path[k]);
                    strcat(temp,args[0]);
                    printf("TEMP | %s",temp);
                    int result=access(temp,F_OK);
                    printf("\nRESULT FINAL %d \n| ",result);
                    // exit(0);
                    if(result==0)
                    {
                        printf("The result is 0 with all_path as %s",all_path[k]);
                        args[0]=strdup(temp);
                        printf("The value is copied to args[0] is %s",args[0]);
                        execv(args[0],args);
                        exit(0);
                        flag=0;
                    }
                    else
                    {
                        printf("CHECKING IN THE NEXT PATH | ");
                    }

                    k++;

                }
                if(flag)//When the executable does not exist in any of the paths
                {
                    eprint();
                    exit(1);
                }


                // strcat(path,args[0]);
                // args[0]=path;
                exit(0);
            }
            else 
            {
                wait(NULL);
                printf("\nPARENT PARENT PARENT PARENT PARENT PARENT PARENT PARENT ");
                
            }
        }
       
    // stream.close();
    }
    else
    {   
        printf("Jumping to shell mode");
        shell();
    }
    // free(command);

    return 1;
}