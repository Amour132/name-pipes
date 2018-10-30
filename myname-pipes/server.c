#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
  int rfd = open("mypipe",O_RDONLY);
  if(rfd < 0)//open fail
  {
    printf("open fail\n");
    exit(1);
  }

  char buff[1024];
  while(1)
  {
    buff[0] = 0;
    printf("please wait...\n");
    ssize_t s = read(rfd,buff,sizeof(buff)-1);
    if(s>0)//read success
    {
      buff[s-1] = 0;
      printf("client say:%s\n",buff);
    }
    else if(s == 0)
    {
      printf("client quit,exit now\n");
      exit(0);
    }
    else
    {
      printf("read error\n");
      exit(1);
    }
  }
  close(rfd);
  return 0;
}
