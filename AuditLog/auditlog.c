#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
    if (argc == 3 && strcmp(argv[1], "--add") == 0)
    {
        int fd = open("audit.log", O_WRONLY | O_CREAT | O_APPEND, 0644);

        if (fd == -1)
        {
            printf("Error opening audit.log file\n");
            return 1;
        }

        write(fd, argv[2], strlen(argv[2]));
        write(fd, "\n", 1);

        printf("Log added successfully.\n");

        close(fd);
    }
    else if (argc == 2 && strcmp(argv[1], "--view") == 0)
    {
        int fd = open("audit.log", O_RDONLY);

        if (fd == -1)
        {
            printf("Log file does not exist.\n");
            return 1;
        }

        char buffer[BUF_SIZE];
        int bytesRead;
        int line = 1;
        int startOfLine = 1;

        while ((bytesRead = read(fd, buffer, BUF_SIZE)) > 0)
        {
            for (int i = 0; i < bytesRead; i++)
            {
                if (startOfLine)
                {
                    printf("%d: ", line);
                    startOfLine = 0;
                }

                printf("%c", buffer[i]);

                if (buffer[i] == '\n')
                {
                    line++;
                    startOfLine = 1;
                }
            }
        }

        close(fd);
    }
    else
    {
        printf("Invalid usage.\n");
        printf("Usage:\n");
        printf("./auditlog --add \"message\"\n");
        printf("./auditlog --view\n");
    }

    return 0;
}
