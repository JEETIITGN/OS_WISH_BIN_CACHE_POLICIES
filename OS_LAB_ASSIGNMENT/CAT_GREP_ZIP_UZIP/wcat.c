#include<stdio.h>
#include<stdlib.h>
int main(char *filename)
{
    char read_outs[100];
    FILE *stream = fopen(filename,"r");
    if (stream==NULL)
    {
        printf("Cannot open file");
        exit(1);
    }
    while(!feof(stream))
    {
        fread(read_outs, sizeof(read_outs), 1, stream);
        printf("%s",read_outs);
    }
    printf("\n");
    return(0);
}