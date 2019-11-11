#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char **argv)
{
    // int flag=0;
    // printf("argv[0] is %s",argv[0]);

    // printf("argv[1] is %s",argv[1]);

    // printf("argv[2] is %s",argv[2]);

    FILE *stream=fopen(argv[2],"r");
    char *str=NULL;
    char *toSearch=argv[1];
    size_t len=0;
    if(stream==NULL)
    {
        printf("CANNOT OPEN FILE");
    }
    while(!feof(stream))
    {
        
        getline(&str,&len,stream);
        // printf("%s",str);
        char *ptr = strstr(str,toSearch);
        if(ptr != NULL)
        {
            printf("%s",str);
        }
    }
    return(0);
}