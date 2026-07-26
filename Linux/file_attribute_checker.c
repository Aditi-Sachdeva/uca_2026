#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]){
    
    if(argc != 2){
        printf("Usage %s <file_name>\n",argv[0]);
        exit(1);
    }

    struct stat fileInfo;

    if(stat(argv[1],&fileInfo) == -1){
        printf("Could not retreive file information\n");
        exit(1);
    }

    printf("=== File Attributes for: %s ===\n",argv[1]);

    if(S_ISREG(fileInfo.st_mode)){
       printf("%-22s %s\n", "File Type:", "Regular File");
    }
    else if(S_ISDIR(fileInfo.st_mode)){
        printf("%-22s %s\n", "File Type:", "Directory");
    }
    else if(S_ISLNK(fileInfo.st_mode)){
        printf("%-22s %s\n", "File Type:", "Symbolic Link");
    }
    else if(S_ISCHR(fileInfo.st_mode)){
        printf("%-22s %s\n", "File Type:", "Character Device");
    }
    else if(S_ISBLK(fileInfo.st_mode)){
        printf("%-22s %s\n", "File Type:", "Block Device");
    }
    else if(S_ISFIFO(fileInfo.st_mode)){
        printf("%-22s %s\n", "File Type:", "FIFO (Named Pipe)");
    }
    else if(S_ISSOCK(fileInfo.st_mode)){
        printf("%-22s %s\n", "File Type:", "Socket");
    }
    else{
        printf("%-22s %s\n", "File Type:", "Unknown");
    }

    printf("%-22s 0%o\n", "Permissions:", fileInfo.st_mode & 0777);

    printf("%-22s %ld bytes\n", "File Size:", fileInfo.st_size);

    printf("%-22s %ld\n", "Hard Links Count:", fileInfo.st_nlink);

    printf("%-22s %d\n", "Owner (UID):", fileInfo.st_uid);

    printf("%-22s %d\n", "Group (GID):", fileInfo.st_gid);

    printf("%-22s %s", "Last Access Time:", ctime(&fileInfo.st_atime));

    printf("%-22s %s", "Last Modification:", ctime(&fileInfo.st_mtime));

    printf("%-22s %s", "Status Change Time:", ctime(&fileInfo.st_ctime));

    return 0;

}
