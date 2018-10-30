#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main()
{
  int wfd = open("mypipe",O_WRONLY);
  if(wfd < 0)//open fail
  {
    printf("open fail\n");
    exit(0);
  }
  char buff[1024];
  while(1)
  {
    buff[0] = 0;
    printf("please enter: ");
    fflush(stdout);
    ssize_t s = read(0,buff,sizeof(buff)-1);
    if(s>0)
    {
      buff[s] = 0; 
      write(wfd,buff,strlen(buff));
    }
    else 
    {
      exit(0);
    }
  }
  close(wfd);
  return 0;
}
