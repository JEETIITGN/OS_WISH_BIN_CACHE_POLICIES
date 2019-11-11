#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char **argv)
{
    char *filename=NULL;
    // size_t len=0;
    int itr;
    char ctr;
    // printf("\nargv[0] is %s",argv[0]);

    // printf("\nargv[1] is %s",argv[1]);

    // printf("\nargv[2] is %s",argv[2]);

    FILE *stream=fopen(argv[1],"r");

    if(argv[2]!=NULL)
    filename=argv[2];
    else
    filename="jeet.txt";
    // FILE *writeStream=fopen(argv[2],"r");
    // else
    FILE *wrstream=fopen(filename,"w");
    
    
    // char temp[100];
    if(stream==NULL)
    {
        printf("CANNOT OPEN FILE");
    }
    while(!feof(stream))
    {
        // if(oddeven%2==0)
        // {
        //     printf("\nDIGIT");
        //     fread(str, 4, 1, stream);
        // }
        // else 
        // {
        //     printf("\nCHARACTER");
        //     fread(str, 1, 1, stream);
        // }
        // getline(&str,&len,stream);
        fread(&itr, sizeof(itr), 1, stream);
        // printf("\n%d",itr);
        fread(&ctr, sizeof(ctr), 1, stream);
        // printf("\n%c",ctr);
        int temp=itr;
        while(temp!=0)
        {
            fwrite(&ctr,1,1,wrstream);
            temp--;
        }
        // if(int(str))
        // printf("ODDEVEN | %d ",oddeven);
        // oddeven++;
    }

    return 0;
}