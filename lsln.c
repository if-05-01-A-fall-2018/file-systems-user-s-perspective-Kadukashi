#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <fcntl.h>
#include <dirent.h>

int main(int argc, char const *argv[])
{
  struct dirent *direntry;
  DIR *directory = opendir(".");
  if (directory == NULL)
  {
    printf("ERROR");
    return 0;
  }
  while ((direntry = readdir(directory)) != NULL)
  {
    struct stat stats;
    if (stat(direntry->d_name, &stats) < 0)
      return 1;

    printf("\n");
    if (S_ISBLK(stats.st_mode))
      printf("b");
    else if (S_ISREG(stats.st_mode))
      printf("-");
    else if (S_ISDIR(stats.st_mode))
      printf("d");
    else if (S_ISCHR(stats.st_mode))
      printf("c");
    else if (S_ISLNK(stats.st_mode))
      printf("l");

    (stats.st_mode & S_IRUSR) ? printf("r") : printf("-");

    (stats.st_mode & S_IWUSR) ? printf("w") : printf("-");

    (stats.st_mode & S_IXUSR) ? printf("x") : printf("-");

    (stats.st_mode & S_IRGRP) ? printf("r") : printf("-");

    (stats.st_mode & S_IWGRP) ? printf("w") : printf("-");

    (stats.st_mode & S_IXGRP) ? printf("x") : printf("-");

    (stats.st_mode & S_IROTH) ? printf("r") : printf("-");

    (stats.st_mode & S_IWOTH) ? printf("w") : printf("-");

    (stats.st_mode & S_IXOTH) ? printf("x ") : printf("- ");

    printf("%d ", stats.st_uid);
    printf("%d ", stats.st_gid);
    printf("%ld \t", stats.st_size);

    char time[18];
    strftime(time, 18, "%Y-%m-%d-%H-%M", localtime(&stats.st_mtime));
    printf("%s ", time);
    printf("%s", direntry->d_name);
  }
  closedir(directory);
  return 0;
}