#include <stdio.h>

int fitBits(int x, int n){

    int shift = 32 + (~n + 1);
    int y = (x << shift) >> shift;
    return !(x ^ y);
}

int main(){

    int x,n;

    scanf("%d %d", &x, &n);

    int ans = fitBits(x,n);

    printf("%d\n", ans);

}
