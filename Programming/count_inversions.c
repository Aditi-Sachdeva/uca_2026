#include <stdio.h>

long long merge(int arr[], int left, int mid, int right){

    int temp[right - left + 1];

    int i = left;
    int j = mid + 1;
    int k = 0;

    long long count = 0;

    while(i <= mid && j <= right){

        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
            count += (mid - i + 1);
        }
    }

    while(i <= mid){
        temp[k++] = arr[i++];
    }

    while(j <= right){
        temp[k++] = arr[j++];
    }

    for(i = left, k = 0; i <= right; i++, k++){
        arr[i] = temp[k];
    }

    return count;
}


long long mergeSort(int arr[], int left, int right){

    long long count = 0;

    if(left < right){

        int mid = (left + right) / 2;

        count += mergeSort(arr, left, mid);

        count += mergeSort(arr, mid + 1, right);

        count += merge(arr, left, mid, right);
    }

    return count;
}


int main(){

    int n;

    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    long long answer = mergeSort(arr, 0, n - 1);

    printf("%lld\n", answer);

    return 0;
}
