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
  int size = buf -> st_size;
  printf("File size: %d\n", size);
  printf("File size(human readable): ");
  if (size == 0)
    printf("%d B", size);
  if (size > 1000000000){
    printf("%d GB ", size / 1000000000);
    size = size % 1000000000;
  }
  if (size > 1000000){
    printf("%d MB ", size / 1000000);
    size = size % 1000000;
  }
  if (size > 1000){
    printf("%d KB ", size / 1000);
    size = size % 1000;
  }
  if (size > 0){
    printf("%d B", size);
    size = 0;
  }
  printf("\n");
  int stmode = buf ->st_mode;
  printf("Mode(permissions): %d\n", stmode);
  char mode[10];
  if (stmode & S_IRUSR)
    mode [0] = 'r';
  else
    mode [0] = '-';
  if (stmode & S_IWUSR)
    mode [1] = 'w';
  else
    mode [1] = '-';
  if (stmode & S_IXUSR)
    mode [2] = 'x';
  else
    mode [2] = '-';
  if (stmode & S_IRGRP)
    mode [3] = 'r';
  else
    mode [3] = '-';
  if (stmode & S_IWGRP)
    mode [4] = 'w';
  else
    mode [4] = '-';
  if (stmode & S_IXGRP)
    mode [5] = 'x';
  else
    mode [5] = '-';
  if (stmode & S_IROTH)
    mode [6] = 'r';
  else
    mode [6] = '-';
  if (stmode & S_IWOTH)
    mode [7] = 'w';
  else
    mode [7] = '-';
  if (stmode & S_IXOTH)
    mode [8] = 'x';
  else
    mode [8] = '-';
  mode[9] = 0;
  printf("Mode(ls -l form): %s\n", mode);
  printf("Time of last access: %s", ctime(&buf -> st_atime));
  return 0;
  free(buf);
} 
