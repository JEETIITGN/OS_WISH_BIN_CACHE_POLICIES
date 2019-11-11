#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int binary_conversion(int);
int main(int argc, char **argv)
{
    // printf("\nargv[0] is %s",argv[0]);

    // printf("\nargv[1] is %s",argv[1]);

    // printf("\nargv[2] is %s",argv[2]);

    if(argv[2]==NULL)
    argv[2]="c.z";

    FILE *stream=fopen(argv[1],"r");
    FILE *wrstream=fopen(argv[2],"w");
    
    char *str=NULL;
    int count=0;
    int i,j,k;
    size_t len=0;
    int bin;
    char *binary=NULL;
    binary=(char *)malloc(32);
    int itr;
    char *ctr=NULL;
    char temp[100];
    i=j=k=0;
    if(stream==NULL)
    {
        printf("CANNOT OPEN FILE");
    }
    while(!feof(stream))
    {
        getline(&str,&len,stream);
        printf("\nSTRING IS %s",str);
        // strcpy(temp,str);
        i=1;
        while(str[i]!='\0')
        {
            // strcpy(binary,"00000000000000000000000000000000");
            // printf("%s",binary);
            j=i;
            // printf("\nBEGIN i= %d and j = %d str[i] is %c\n",i,j,str[i]);
            count=0;
            while(str[j]==str[i])
            {
                count++;
                j++;
            }
            printf("\nCOUNT IS |%d %lu",count,sizeof(int));
            itr=count;
            printf("\nPTR IS |%d",itr);
            // fwrite(itr,4, sizeof(itr),wrstream);
            fwrite(&itr,sizeof(int),1, wrstream);
            char ch=str[i];
            printf("\nCHAR IS %c\n",ch);
            fwrite(&ch, sizeof(ch),1,wrstream);
            
            // // exit(0);
            // printf("\nThe count of %c is %d ",str[i],count);
            // bin=binary_conversion(count);
            // // binary=strdup(bin);
            // printf("\nBINARY CONVERTED NO IS %d",bin);
            // // length=strlen()
            // k=18;
            
            // while(bin!=0)
            // {
            //     char ch=bin%10;
            //     printf("character is %c %d",ch,bin);
            // binary[k]=bin%10;
            // bin/=10;
            // k++;
            // }
            // printf("\nSTRCPY | %s ",binary);
            // exit(0);
            
            // // strcpy(binary,(char)bin);
            
            // printf("%x%c",count,str[i]);
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