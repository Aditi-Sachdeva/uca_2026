#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    if(argc != 2){
        printf("Usage %s <file_name>\n", argv[0]);
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");
    FILE *out = fopen("output.c", "w");

    if(fp == NULL || out == NULL){
        printf("File error\n");
        exit(1);
    }

    int ch;
    int next;

    int string = 0;
    int character = 0;

    while((ch = fgetc(fp)) != EOF){
    
        if(ch == '"' && character == 0){
            string = !string;
            fputc(ch, out);
        }
        else if(ch == '\'' && string == 0){
            character = !character;
            fputc(ch, out);
        }
        else if(ch == '/' && string == 0 && character == 0){
            
            next = fgetc(fp);

            if(next == '/'){

                while((ch = fgetc(fp)) != '\n' && ch != EOF);

                if(ch == '\n'){
                    fputc(ch, out);
                }
            }
            else if(next == '*'){

                while((ch = fgetc(fp)) != EOF){

                    if(ch == '*'){
                        next = fgetc(fp);

                        if(next == '/'){
                            break;
                        }
                    }
                }
            }
            else{
                fputc(ch, out);
                fputc(next, out);
            }
        }
        else
        {
            fputc(ch, out);
        }
    }

    fclose(fp);
    fclose(out);

    printf("Comments removed. Check output.c\n");

    return 0;
}
