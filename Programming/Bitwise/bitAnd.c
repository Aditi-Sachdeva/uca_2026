#include <stdio.h>

int bitAnd(int x, int y){

    int ans = ~(~x | ~y);
    return ans;
}

int main(){

    int x,y;

    scanf("%d %d",&x,&y);
    
    int ans = bitAnd(x,y);
    printf("%d\n",ans);

    return 0;
}
