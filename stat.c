#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>

int main(){
  int fd = open("stat", O_CREAT, 0644);
  struct stat *buf = (struct stat *)malloc(sizeof(struct stat));
  int a = stat("stat", buf);
  close(fd);
  printf("File size: %d B\n",(buf -> st_size) * 10);
  int stmode = buf ->st_mode;
  printf("Mode(permissions): %d\n", stmode);
  char mode[9];
  if (stmode & S_IRUSR)
    mode [1] = 'r';
  else
    mode [1] = '-';
  if (stmode & S_IWUSR)
    mode [2] = 'w';
  else
    mode [2] = '-';
  if (stmode & S_IXUSR)
    mode [3] = 'x';
  else
    mode [3] = '-';
  if (stmode & S_IRGRP)
    mode [4] = 'r';
  else
    mode [4] = '-';
  if (stmode & S_IWGRP)
    mode [5] = 'w';
  else
    mode [5] = '-';
  if (stmode & S_IXGRP)
    mode [6] = 'x';
  else
    mode [6] = '-';
  if (stmode & S_IROTH)
    mode [7] = 'r';
  else
    mode [7] = '-';
  if (stmode & S_IWOTH)
    mode [8] = 'w';
  else
    mode [8] = '-';
  if (stmode & S_IXOTH)
    mode [9] = 'x';
  else
    mode [9] = '-';
  printf("Mode(ls -l form): %s\n", mode);
  printf("Time of last access: %s", ctime(&buf -> st_atime));
  return 0;
}  
