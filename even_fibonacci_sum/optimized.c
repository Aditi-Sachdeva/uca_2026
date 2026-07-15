#include <stdio.h>

int evenFibonacciSum(int n){
    int e1 = 2;
    int e2 = 8;
    int next;
    int sum = 0;

    while (e1 <= n){
        sum += e1;
        next = 4 * e2 + e1;
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
