#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
// #include<string.h>

int main(){
printf("Welcome to WIscosin SHell");
char command[100];
// printf("\nwish>");
// scanf("%s",&command);
// printf("about to print the entered command");
printf("\nThe cmd is %s\n",command);

char *path[]={"/bin/",NULL};
// char dest[100]="/bin/";
// strcat(dest,"ls");
printf("The path is %s\n",*path[0]);
strcat(*path[0],"ls");
printf("dest is %s \n",path[0]);
execv(path[0],path);
// printf(strcmp(command,"exit"));
// while(strcmp(command,"exit")!=0)
// {
//     printf("0");
//     printf("\nwish>");
//     scanf("%s",&command);
// }
// // else
//     printf("Exiting");

return 1;
}