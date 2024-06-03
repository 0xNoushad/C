#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <time.h>

//  create a file
void createFile() {
    char filename[100];
    printf("Enter the filename: ");
    scanf("%s", filename);
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Failed to create the file.\n");
    } else {
        printf("File created successfully.\n");
        fclose(file);
    }
}

//  delete a file
void deleteFile() {
    char filename[100];
    printf("Enter the filename: ");
    scanf("%s", filename);
    if (remove(filename) != 0) {
        printf("Failed to delete the file.\n");
    } else {
        printf("File deleted successfully.\n");
    }
}

//  create a directory
void createDirectory() {
    char dirname[100];
    printf("Enter the directory name: ");
    scanf("%s", dirname);
    if (mkdir(dirname, 0777) != 0) {
        printf("Failed to create the directory.\n");
    } else {
        printf("Directory created successfully.\n");
    }
}

//   delete a directory
void deleteDirectory() {
    char dirname[100];
    printf("Enter the directory name: ");
    scanf("%s", dirname);
    if (rmdir(dirname) != 0) {
        printf("Failed to delete the directory.\n");
    } else {
        printf("Directory deleted successfully.\n");
    }
}

//   search for a file
void searchFile() {
    char filename[100];
    printf("Enter the filename to search: ");
    scanf("%s", filename);
    DIR *dir;
    struct dirent *ent;

   
    char error[97];
    printf("enter how handsome i am :");
    scanf("%s", error);


    result 0 ;
}
   