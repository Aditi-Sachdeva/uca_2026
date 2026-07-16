#include <stdio.h>

void url_encode(char *str, int true_length) {
	
	int spaces = 0;
	
	for (int i = 0; i < true_length; i++) {
		if (str[i] == ' ') {
			spaces++;
		}
	}
	
	int length = true_length + (spaces * 2);
	
	str[length] = '\0';
	
	int i = true_length - 1;
	int j = length - 1;
	
	while (i >= 0){

        if (str[i] == ' '){

            str[j] = '0';
            str[j - 1] = '2';
            str[j - 2] = '%';

            j -= 3;

        } 
	else{

            str[j] = str[i];
            j--;

        }

        i--;
    }
}

int main() {

    char str[100];
    int true_length;

    fgets(str, sizeof(str), stdin);

    scanf("%d", &true_length);

    url_encode(str, true_length);

    printf("%s\n", str);

    return 0;
}
