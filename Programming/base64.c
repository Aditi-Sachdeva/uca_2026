#include <stdio.h>
#include <string.h>

char table[] ="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

void base64Encode(char input[]){

    char output[1000];

    int len = strlen(input);
    int i = 0;
    int j = 0;

    while(i < len){

        unsigned char b1 = input[i++];

        unsigned char b2 = 0;
        int hasB2 = 0;

        if(i < len){
            b2 = input[i++];
            hasB2 = 1;
        }

        unsigned char b3 = 0;
        int hasB3 = 0;

        if(i < len){
            b3 = input[i++];
            hasB3 = 1;
        }

        int c1 = b1 >> 2;
        int c2 = ((b1 & 3) << 4) | (b2 >> 4);
        int c3 = ((b2 & 15) << 2) | (b3 >> 6);
        int c4 = b3 & 63;

        output[j++] = table[c1];
        output[j++] = table[c2];

        if(hasB2){
            output[j++] = table[c3];
        }
        else{
            output[j++] = '=';
        }

        if(hasB3){
            output[j++] = table[c4];
        }
        else{
            output[j++] = '=';
        }

    }

    output[j] = '\0';

    printf("Base64: %s\n", output);
}

int main(){

    char input[1000];

    scanf("%s", input);

    base64Encode(input);

    return 0;
}
