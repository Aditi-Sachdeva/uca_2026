#include <stdio.h>

int bang(int x){
    return ((x | (~x + 1)) >> 31) + 1;
}

int main(){

    int x;

    scanf("%d", &x);

    int ans = bang(x);

    printf("%d\n",ans);
}
