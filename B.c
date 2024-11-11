/*Write a C program to identify the type (Directory, character device, block device, regular file, FIFO or pipe, symbolic link, or socket) of a given file using the stat() system call.*/
#include <stdio.h>
#include <sys/stat.h>

int main() {
    char filename[100];
    struct stat fileStat;

    printf("Enter the filename: ");
    scanf("%s", filename);

    if (stat(filename, &fileStat) == 0) {
        printf("File: %s\n", filename);
        if (S_ISREG(fileStat.st_mode)) printf("Type: Regular File\n");
        else if (S_ISDIR(fileStat.st_mode)) printf("Type: Directory\n");
        else if (S_ISCHR(fileStat.st_mode)) printf("Type: Character Device\n");
        else if (S_ISBLK(fileStat.st_mode)) printf("Type: Block Device\n");
        else if (S_ISFIFO(fileStat.st_mode)) printf("Type: FIFO or Pipe\n");
        else if (S_ISLNK(fileStat.st_mode)) printf("Type: Symbolic Link\n");
        else if (S_ISSOCK(fileStat.st_mode)) printf("Type: Socket\n");
        else printf("Type: Unknown\n");
    } else {
        printf("Cannot access file: %s\n", filename);
    }

    return 0;
}


/*Enter the filename: example.txt
File: example.txt
Type: Regular File
*/