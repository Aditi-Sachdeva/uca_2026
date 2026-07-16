#include <stdio.h>
#include <string.h>

void reverse_string(char *str){

        int len  = strlen(str);
        if (len > 0 && str[len - 1] == '\n') {
		str[len - 1] = '\0';
		len--;
	}
	int left = 0;
        int right = len - 1;

        while(left < right){
                char temp = str[left];
                str[left] = str[right];
                str[right] = temp;
                left++;
                right--;
        }
}

int main(){
	
	char str[100];
	
	fgets(str, sizeof(str), stdin);
	
	reverse_string(str);
	
	printf("%s\n", str);

	return 0;
}

