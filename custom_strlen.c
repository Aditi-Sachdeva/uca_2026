#include <stdio.h>

int my_strlen(const char *str){

        int length = 0;

        while(str[length] != '\0'){
                if(str[length] == '\n'){
			break;
		}
		length++;
        }

        return length;

}


int main(){
	char str[100];
	
	fgets(str, sizeof(str), stdin);

	int len = my_strlen(str);
	printf("%d\n",len);

	return 0;
}


