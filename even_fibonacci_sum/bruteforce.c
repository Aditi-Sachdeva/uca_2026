#include <stdio.h>

int evenFibonacciSum(int n){
    int e1 = 1;
    int e2 = 1;
    int next;
    int sum = 0;

    while (e1 <= n){

        if (e1 % 2 == 0){
            sum += e1;
	}
        next = e1 + e2;
        e1 = e2;
        e2 = next;
    }

    return sum;
}

int main(){

    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Sum of even Fibonacci numbers = %d\n", evenFibonacciSum(n));

    return 0;
}
