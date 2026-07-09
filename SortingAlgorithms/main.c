#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int sizes[8] = { 8000,12000,16000,20000,24000,28000,32000,36000};

void bubbleSort(int arr[], int n){

    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertionSort(int arr[], int n){

    for(int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}


void selectionSort(int arr[], int n){

    for(int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}


void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high){

    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);

    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1];
    int R[n2];

    for(int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for(int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while(i < n1)
        arr[k++] = L[i++];

    while(j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right){

    if(left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}


void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && arr[left] > arr[largest])
        largest = left;

    if(right < n && arr[right] > arr[largest])
        largest = right;

    if(largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for(int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for(int i = n - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}


double elapsed_ms(clock_t start, clock_t end)
{
    return ((double)(end - start) * 1000) / CLOCKS_PER_SEC;
}

void generateRandom(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        arr[i] = rand() % 100000;
}

void generateAscending(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        arr[i] = i;
}

void generateDescending(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        arr[i] = n - i;
}

                      


int main()
{
    srand(time(NULL));

    int *original;
    int *arr;
    clock_t start, end;

    printf("\nBubble Sort\n");

    for(int s = 0; s < 8; s++)
    {
        int n = sizes[s];

        original = (int *)malloc(n * sizeof(int));
        arr = (int *)malloc(n * sizeof(int));

        if(original == NULL || arr == NULL)
        {
            printf("Memory allocation failed.\n");
            return 1;
        }

        printf("\nArray Size: %d\n", n);

        generateRandom(original, n);
        memcpy(arr, original, n * sizeof(int));
        start = clock();
        bubbleSort(arr, n);
        end = clock();
        printf("Random: %f ms\n", elapsed_ms(start, end));

        generateAscending(original, n);
        memcpy(arr, original, n * sizeof(int));
        start = clock();
        bubbleSort(arr, n);
        end = clock();
        printf("Ascending: %f ms\n", elapsed_ms(start, end));

        generateDescending(original, n);
        memcpy(arr, original, n * sizeof(int));
        start = clock();
        bubbleSort(arr, n);
        end = clock();
        printf("Descending: %f ms\n", elapsed_ms(start, end));

        free(original);
        free(arr);
    }

    printf("\nInsertion Sort\n");

    for(int s = 0; s < 8; s++)
    {
        int n = sizes[s];

        original = (int *)malloc(n * sizeof(int));
        arr = (int *)malloc(n * sizeof(int));

        if(original == NULL || arr == NULL)
        {
            printf("Memory allocation failed.\n");
            return 1;
        }

        printf("\nArray Size: %d\n", n);

        generateRandom(original, n);
        memcpy(arr, original, n * sizeof(int));
        start = clock();
        insertionSort(arr, n);
        end = clock();
        printf("Random: %f ms\n", elapsed_ms(start, end));

        generateAscending(original, n);
        memcpy(arr, original, n * sizeof(int));
        start = clock();
        insertionSort(arr, n);
        end = clock();
        printf("Ascending: %f ms\n", elapsed_ms(start, end));

        generateDescending(original, n);
        memcpy(arr, original, n * sizeof(int));
        start = clock();
        insertionSort(arr, n);
        end = clock();
        printf("Descending: %f ms\n", elapsed_ms(start, end));

        free(original);
        free(arr);
    }

    printf("\nSelection Sort\n");

    for(int s = 0; s < 8; s++)
    {
        int n = sizes[s];

        original = (int *)malloc(n * sizeof(int));
        arr = (int *)malloc(n * sizeof(int));

        if(original == NULL || arr == NULL)
        {
            printf("Memory allocation failed.\n");
            return 1;
        }

        printf("\nArray Size: %d\n", n);

        generateRandom(original, n);
        memcpy(arr, original, n * sizeof(int));
        start = clock();
        selectionSort(arr, n);
        end = clock();
        printf("Random: %f ms\n", elapsed_ms(start, end));

        generateAscending(original, n);
        memcpy(arr, original, n * sizeof(int));
        start = clock();
        selectionSort(arr, n);
        end = clock();
        printf("Ascending: %f ms\n", elapsed_ms(start, end));

        generateDescending(original, n);
        memcpy(arr, original, n * sizeof(int));
        start = clock();
        selectionSort(arr, n);
        end = clock();
        printf("Descending: %f ms\n", elapsed_ms(start, end));

        free(original);
        free(arr);
    }      printf("\nQuick Sort\n");

    for(int s = 0; s < 8; s++)
    {
        int n = sizes[s];

        original = (int *)malloc(n * sizeof(int));
        arr = (int *)malloc(n * sizeof(int));

        if(original == NULL || arr == NULL)
        {
            printf("Memory allocation failed.\n");
            return 1;
        }

        printf("\nArray Size: %d\n", n);

        generateRandom(original, n);
        memcpy(arr, original, n * sizeof(int));
        start = clock();
        quickSort(arr, 0, n - 1);
        end = clock();
        printf("Random: %f ms\n", elapsed_ms(start, end));

        generateAscending(original, n);
        memcpy(arr, original, n * sizeof(int));
        start = clock();
        quickSort(arr, 0, n - 1);
        end = clock();
        printf("Ascending: %f ms\n", elapsed_ms(start, end));

        generateDescending(original, n);
        memcpy(arr, original, n * sizeof(int));
        start = clock();
        quickSort(arr, 0, n - 1);
        end = clock();
        printf("Descending: %f ms\n", elapsed_ms(start, end));

        free(original);
        free(arr);
    }

    printf("\nMerge Sort\n");

    for(int s = 0; s < 8; s++)
    {
        int n = sizes[s];

        original = (int *)malloc(n * sizeof(int));
        arr = (int *)malloc(n * sizeof(int));

        if(original == NULL || arr == NULL)
        {
            printf("Memory allocation failed.\n");
            return 1;
        }

        printf("\nArray Size: %d\n", n);

        generateRandom(original, n);
        memcpy(arr, original, n * sizeof(int));
        start = clock();
        mergeSort(arr, 0, n - 1);
        end = clock();
        printf("Random: %f ms\n", elapsed_ms(start, end));

        generateAscending(original, n);
        memcpy(arr, original, n * sizeof(int));
        start = clock();
        mergeSort(arr, 0, n - 1);
        end = clock();
        printf("Ascending: %f ms\n", elapsed_ms(start, end));

        generateDescending(original, n);
        memcpy(arr, original, n * sizeof(int));
        start = clock();
        mergeSort(arr, 0, n - 1);
        end = clock();
        printf("Descending: %f ms\n", elapsed_ms(start, end));

        free(original);
        free(arr);
    }

    printf("\nHeap Sort\n");

    for(int s = 0; s < 8; s++)
    {
        int n = sizes[s];

        original = (int *)malloc(n * sizeof(int));
        arr = (int *)malloc(n * sizeof(int));

        if(original == NULL || arr == NULL)
        {
            printf("Memory allocation failed.\n");
            return 1;
        }

        printf("\nArray Size: %d\n", n);

        generateRandom(original, n);
        memcpy(arr, original, n * sizeof(int));
        start = clock();
        heapSort(arr, n);
        end = clock();
        printf("Random: %f ms\n", elapsed_ms(start, end));

        generateAscending(original, n);
        memcpy(arr, original, n * sizeof(int));
        start = clock();
        heapSort(arr, n);
        end = clock();
        printf("Ascending: %f ms\n", elapsed_ms(start, end));

        generateDescending(original, n);
        memcpy(arr, original, n * sizeof(int));
        start = clock();
        heapSort(arr, n);
        end = clock();
        printf("Descending: %f ms\n", elapsed_ms(start, end));

        free(original);
        free(arr);
    }

    return 0;
}
