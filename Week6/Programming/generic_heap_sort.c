#include <stdio.h>
#include <string.h>

void swap(void *a, void *b, size_t size){

    char temp[size];

    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
}

int compare_int(const void *a, const void *b){

    int x = *(const int *)a;
    int y = *(const int *)b;

    if(x < y){
        return -1;
    }
    else if(x > y){
        return 1;
    }
    else{
        return 0;
    }
}

int compare_char(const void *a, const void *b){

    char x = *(const char *)a;
    char y = *(const char *)b;

    if(x > y){
        return 1;
    }
    else if (x < y){
        return -1;
    }
    else{
        return 0;
    }
}

void heapify(void *arr, size_t n, size_t i, size_t size, int (*compare)(const void *, const void *)){

    size_t largest = i;
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;

    if(left < n && compare((char *)arr + left * size, (char *)arr + largest * size) > 0){

        largest = left;
    }

    if(right < n && compare((char *)arr + right * size, (char *)arr + largest * size) > 0){

        largest = right;
    }

    if(largest != i){

        swap((char *)arr + i * size, (char *)arr + largest * size, size);

        heapify(arr, n, largest, size, compare);
    }
}

void heap_sort(void *arr, size_t n, size_t size, int (*compare)(const void *, const void *)){

    for(size_t i = n / 2; i > 0; i--){
        heapify(arr, n, i - 1, size, compare);
    }

    for(size_t i = n; i > 1; i--){

        swap((char *)arr,(char *)arr + (i - 1) * size,size);

        heapify(arr, i - 1, 0, size, compare);
    }
}


int main(){

    int arr1[] = {40, 10, 30, 50, 20};

    size_t n = sizeof(arr1) / sizeof(arr1[0]);

    heap_sort(arr1, n, sizeof(int), compare_int);

    for (size_t i = 0; i < n; i++){
        printf("%d ", arr1[i]);
    }

    printf("\n");

    char arr2[] = {'c', 'a', 'e', 'b', 'd'};

    size_t m = sizeof(arr2) / sizeof(arr2[0]);

    heap_sort(arr2, m, sizeof(char), compare_char);

    for (size_t i = 0; i < m; i++){
        printf("%c ", arr2[i]);
    }

    printf("\n");

    return 0;
}
