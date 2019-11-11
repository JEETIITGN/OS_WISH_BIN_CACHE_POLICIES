#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char **argv)
{
    // printf("\nargv[0] is %s",argv[0]);

    // printf("\nargv[1] is %s",argv[1]);

    // printf("\nargv[2] is %s",argv[2]);

    FILE *stream=fopen(argv[1],"r");
    // FILE *writeStream=fopen(argv[2],"r");
    
    char *str=NULL;
    int count=0;
    int i,j,k;
    size_t len=0;
    int bin;
    char *binary=NULL;
    // char temp[100];
    i=j=k=0;
    if(stream==NULL)
    {
        printf("CANNOT OPEN FILE");
    }
    while(!feof(stream))
    {
        getline(&str,&len,stream);
        // printf("%s",str);
        // strcpy(temp,str);
        i=0;
        // while(str[i]!='\0')
        // {
        //     printf("WALAAAAHa");
        //     i++;
        // }
        while(str[i]!='\0')
        {
            j=i;
            // printf("\nBEGIN i= %d and j = %d\n",i,j);
            count=0;
            while(str[j]==str[i])
            {
                count++;
                j++;
            }
            bin=binary_conversion(count);
            printf("%s%c",count,str[i]);
            i+=count;
            // printf("\nEND i= %d and j = %d\n",i,j);
        }        
    }

    return 0;
}
//REFERENCE: https://www.sanfoundry.com/c-program-binary-equivalent-integer-recursion/
int binary_conversion(int num)
{
    if (num == 0)
    {
        return 0;
    }
    else
    {
        return (num % 2) + 10 * binary_conversion(num / 2);
    }
}