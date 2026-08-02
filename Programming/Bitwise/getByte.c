#include <stdio.h>

int getByte(int x, int n){

    return (x >> (n << 3)) & 0xFF;
}

int main(){

    int x,n;

    scanf("%d %d",&x,&n);

    int ans = getByte(x,n);

    printf("%d\n", ans);
}
