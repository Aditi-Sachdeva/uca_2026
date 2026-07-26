#include <stdio.h>

void merge(int nums[], int index[], int count[], int left, int mid, int right){

    int temp[right - left + 1];

    int i = left;
    int j = mid + 1;
    int k = 0;

    int smaller = 0;

    while(i <= mid && j <= right){

        if(nums[index[j]] < nums[index[i]]){
            smaller++;

            temp[k] = index[j];
            k++;
            j++;
        }
        else{
            count[index[i]] += smaller;

            temp[k] = index[i];
            k++;
            i++;
        }
    }

    while(i <= mid){
        count[index[i]] += smaller;

        temp[k] = index[i];
        k++;
        i++;
    }

    while(j <= right){
        temp[k] = index[j];
        k++;
        j++;
    }

    k = 0;

    for(i = left; i <= right; i++){
        index[i] = temp[k];
        k++;
    }
}


void mergeSort(int nums[], int index[], int count[], int left, int right){

    if(left < right){

        int mid = (left + right) / 2;

        mergeSort(nums, index, count, left, mid);

        mergeSort(nums, index, count, mid + 1, right);

        merge(nums, index, count, left, mid, right);
    }
}


void countSmaller(int nums[], int n, int count[]){

    int index[n];

    for(int i = 0; i < n; i++){
        index[i] = i;
        count[i] = 0;
    }

    mergeSort(nums, index, count, 0, n - 1);
}


int main(){

    int n;

    scanf("%d", &n);

    int nums[n];
    int count[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &nums[i]);
    }

    countSmaller(nums, n, count);

    for(int i = 0; i < n; i++){
        printf("%d ", count[i]);
    }

    printf("\n");
    return 0;
}
