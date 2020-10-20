#include<stdio.h>
#include<unistd.h>
int main (int argc,char const *argv[])
{    
unsigned char rbuff[128]; 
pid_t id;
int pfd[2];
pipe(pfd);

id =fork();
if (0==id)
{
   //child processs
   read(pfd[0] ,rbuff, 128);
   printf("child:%s\n",rbuff);
}
else
{
   //parent processs 
   write(pfd[1],"cdac\n",5);
   close(pfd[1]);
}
return 0;
}
