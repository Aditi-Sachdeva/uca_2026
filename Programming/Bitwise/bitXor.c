#include <stdio.h>

int bitXor(int x, int y){

    return ~(~(~x & y) & ~(x & ~y));
}

int main(){

    int x,y;

    scanf("%d %d",&x,&y);

    int ans = bitXor(x,y);

    printf("%d\n",ans);
}

