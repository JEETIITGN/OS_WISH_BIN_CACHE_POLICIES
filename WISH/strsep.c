#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>

int main(){
printf("Welcome to WIscosin SHell");
char *command=strdup("ls -l");
char *arguments;
char *args[100];

int i=1;
while((arguments=strsep(&command," "))!=NULL)
{
    args[i]=arguments;
    printf("\nArgument is %s\n",args[i]);

    i++;
}

return 1;
}