#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>

int main(){
printf("Welcome to WIscosin SHell\n");


char path[]="/bin/\0";

printf("The path is %s\n",path);
printf("The address path is %p\n",path);
// printf("The path is %s\n",*path);
// char cat[100];
// cat=*path;
strcat(path,"ls");
printf("dest is %s \n",path);
// execv(path,)
char *args[]={"./EXEC",NULL};
printf("%p\n",args[0]);
printf("%p\n",args);
execv(path,args);
return 1;
}