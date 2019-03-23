#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
  if (argc != 2)
  {
    return 0;
  }
  struct stat stats;
  if (stat(argv[1], &stats) < 0)
  {
    return 1;
  }
  printf("\n");
  printf("--------------------%s--------------------\n", argv[1]);
  printf("\n");
  printf("File Type: \t\t");
  if (S_ISBLK(stats.st_mode))
    printf("Block device");
  else if (S_ISREG(stats.st_mode))
    printf("Regular file");
  else if (S_ISDIR(stats.st_mode))
    printf("Directory");
  else if (S_ISCHR(stats.st_mode))
    printf("Character device");
  else if (S_ISLNK(stats.st_mode))
    printf("Symbolic link");
  printf("\n");
  printf("Access privileges:\t");

  if (stats.st_mode & S_IRUSR)
    printf("r");
  else
    printf("-");

  if (stats.st_mode & S_IWUSR)
    printf("w");
  else
    printf("-");

  if (stats.st_mode & S_IXUSR)
    printf("x");
  else
    printf("-");

  if (stats.st_mode & S_IRGRP)
    printf("r");
  else
    printf("-");

  if (stats.st_mode & S_IWGRP)
    printf("w");
  else
    printf("-");

  if (stats.st_mode & S_IXGRP)
    printf("x");
  else
    printf("-");

  if (stats.st_mode & S_IROTH)
    printf("r");
  else
    printf("-");

  if (stats.st_mode & S_IWOTH)
    printf("w");
  else
    printf("-");

  if (stats.st_mode & S_IXOTH)
    printf("x");
  else
    printf("-");

  printf("\n");

  printf("File inode: \t\t%ld\n", stats.st_ino);
  printf("Device Numbers: \tdev = %ld; rdev = %ld\n", stats.st_dev, stats.st_rdev);
  printf("Number of Links: \t%ld\n", stats.st_nlink);
  printf("UID: \t\t\t%d\n", stats.st_uid);
  printf("GID: \t\t\t%d\n", stats.st_gid);
  printf("File size: \t\t%ld\n", stats.st_size);
  printf("Last access: \t\t%s", asctime(gmtime(&stats.st_atime)));
  printf("Last modification: \t%s", asctime(gmtime(&stats.st_mtime)));
  printf("Last inode change: \t%s", asctime(gmtime(&stats.st_ctime)));
  return 0;
}
