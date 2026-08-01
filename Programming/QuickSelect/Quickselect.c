#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int left, int right){

    int pivot = arr[right];
    int i = left;

    for (int j = left; j < right; j++){

        if (arr[j] <= pivot){
            swap(&arr[i], &arr[j]);
            i++;
        }

    }

    swap(&arr[i], &arr[right]);
    return i;
}

void quickselect(int arr[], int left, int right, int k){

    if (left < right){

        int pivotIndex = partition(arr, left, right);

        if (pivotIndex == k){
            return;
        }
        else if (pivotIndex > k){
            quickselect(arr, left, pivotIndex - 1, k);
        }
        else{
            quickselect(arr, pivotIndex + 1, right, k);
        }
    }
}

int main(){

    int n, k;

    printf("Enter dataset size: ");
    scanf("%d", &n);

    printf("Enter k: ");
    scanf("%d", &k);

    if (k <= 0 || k > n)
    {
        printf("Invalid value of k\n");
        return 1;
    }

    int *arr = (int *)malloc(n * sizeof(int));

    srand(time(NULL));

    for (int i = 0; i < n; i++){
        arr[i] = rand() % 1000000;
    }

    clock_t start = clock();

    quickselect(arr, 0, n - 1, k - 1);

    clock_t end = clock();

    double runtime = ((double)(end - start) / CLOCKS_PER_SEC) * 1000;

    printf("First %d smallest elements:\n", k);

    for (int i = 0; i < k; i++){
        printf("%d ", arr[i]);
    }

    printf("\nExecution Time: %.3f ms\n", runtime);

    free(arr);

    return 0;
}
