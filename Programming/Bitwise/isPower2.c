#include <stdio.h>

int isPower2(int x){
    return x > 0 && (x & (x-1)) == 0;
}

int main(){

    int x;

    scanf("%d",&x);

    int ans = isPower2(x);

    if(ans == 1){
        printf("%d is power of 2\n",x);
    }
    else{
        printf("%d is not power of 2\n",x);
   }
}
