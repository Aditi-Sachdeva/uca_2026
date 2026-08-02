#include <stdio.h>

int logicalShift(int x, int n){
    
    int mask = ~(((1 << 31) >> n) << 1);
    return (x >> n) & mask;
}

int main(){

    int x,n;

    scanf("%d %d", &x, &n);

    int ans = logicalShift(x,n);

    printf("%d\n", ans);
}
