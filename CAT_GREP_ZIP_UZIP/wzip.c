#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char **argv)
{
    // printf("\n\nARGC | %d",argc);
    // printf("\nargv[0] is %s",argv[0]);

    // printf("\nargv[1] is %s",argv[1]);

    // printf("\nargv[2] is %s",argv[2]);

    if(argv[argc-1]==NULL)
    argv[argc-1]="c.z";

    
    char *str=NULL;
    int count=0;
    int i,j,k;
    size_t len=0;
    // int bin;
    char *binary=NULL;
    binary=(char *)malloc(32);
    int itr;
    // char *ctr=NULL;
    // char temp[100];
    i=j=k=0;
    int fd=1;
    FILE *wrstream=fopen(argv[argc-1],"w");
    while(argv[fd]!=NULL)
    {
        // printf("\n\n\n\nARGV IS %s\n\n\n\n",argv[fd]);
        FILE *stream=fopen(argv[fd],"r");
        fd++;
        if(stream==NULL)
        {
            printf("CANNOT OPEN FILE");
        }
        while(!feof(stream))
        {
            getline(&str,&len,stream);
            // printf("\nSTRING IS %s",str);
            // strcpy(temp,str);
            i=1;
            while(str[i]!='\0')
            {
                j=i;
                // printf("\nBEGIN i= %d and j = %d str[i] is %c\n",i,j,str[i]);
                count=0;
                while(str[j]==str[i])
                {
                    count++;
                    j++;
                }
                // printf("\nCOUNT IS |%d %lu",count,sizeof(int));
                itr=count;
                // printf("\nPTR IS |%d",itr);
                // fwrite(itr,4, sizeof(itr),wrstream);
                fwrite(&itr,sizeof(int),1, wrstream);
                char ch=str[i];
                // printf("\nCHAR IS %c\n",ch);
                fwrite(&ch, sizeof(ch),1,wrstream);
                
                i+=count;
                // printf("\nEND i= %d and j = %d\n",i,j);
            }  
                
        }
    }
    return 0;
}