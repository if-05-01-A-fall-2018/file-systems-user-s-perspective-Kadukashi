#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
    if (argc != 3) return 0;
    int file = open(argv[1], O_RDONLY);
    if (file < 0) {
        printf("ERROR\n");
        return 0;
    }

    int offset = lseek(check_file, 0, SEEK_END);

    char string[offset];

    offset = lseek(check_file, 0, 0);

    read(file, &string, sizeof(string));
    file = open(argv[2], O_TRUNC);
    file = open(argv[2], O_WRONLY);

    int test = write(file, string, sizeof(string));
    if (test < 0) {
        printf("ERROR\n");
        return 0;

    }

    printf("Successfully copied!\n");
    return 0;
}
