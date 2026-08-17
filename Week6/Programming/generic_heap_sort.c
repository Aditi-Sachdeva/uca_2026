#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student{
    int id;
    float cgpa;
    char *name;
};

void swap(void *a, int i, int j, int sz){
    
    char *temp = malloc(sz);
    char *t1 = (char *)a + i * sz;
    char *t2 = (char *)a + j * sz;

    memcpy(temp, t1, sz);
    memcpy(t1, t2, sz);
    memcpy(t2, temp, sz);

    free(temp);
}

void heapify(void *a, int n, int i, int sz, int (*cmp)(const void *, const void *)){

    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n){
        if (cmp((char *)a + l * sz,(char *)a + largest * sz) > 0){
            largest = l;
        }
    }

    if (r < n){
        if (cmp((char *)a + r * sz,(char *)a + largest * sz) > 0){
            largest = r;
        }
    }

    if (largest != i){
        swap(a, i, largest, sz);
        heapify(a, n, largest, sz, cmp);
    }
}

void heap_sort(void *a, int n, int sz,int (*cmp)(const void *, const void *)){

    for (int i = n / 2 - 1; i >= 0; i--){
        heapify(a, n, i, sz, cmp);
    }

    for (int i = n - 1; i > 0; i--){
        swap(a, 0, i, sz);
        heapify(a, i, 0, sz, cmp);
    }
}

int intCmp(const void *i, const void *j){
    
    int x = *(const int *)i;
    int y = *(const int *)j;

    return (x > y) - (x < y);
}

int floatCmp(const void *i, const void *j){
    
    float x = *(const float *)i;
    float y = *(const float *)j;

    return (x > y) - (x < y);
}

int studentCgpaCmp(const void *i, const void *j){
    
    const struct student *x = (const struct student *)i;
    const struct student *y = (const struct student *)j;

    return (x->cgpa > y->cgpa) - (x->cgpa < y->cgpa);
}

void printInt(int *a, int n){
    
    for (int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }

    printf("\n");
}

void printFloat(float *a, int n){
    
    for (int i = 0; i < n; i++){
        printf("%.2f ", a[i]);
    }

    printf("\n");
}

void printStudents(struct student *s, int n){
    
    for (int i = 0; i < n; i++){
        printf("%d:%s:%.2f ", s[i].id, s[i].name, s[i].cgpa);
    }

    printf("\n");
}

int main(){
    
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    heap_sort(arr, n, sizeof(int), intCmp);

    printf("Sorted integers: ");
    printInt(arr, n);

    float f[] = {1.2f, 3.4f, 0.7f, 0.8f, 0.4f, 0.3f};
    int nf = sizeof(f) / sizeof(f[0]);

    heap_sort(f, nf, sizeof(float), floatCmp);

    printf("Sorted floats: ");
    printFloat(f, nf);

    struct student s[] = {
        {1, 3.2f, "Alice"},
        {2, 2.5f, "Bob"},
        {3, 3.8f, "Charlie"},
        {4, 1.9f, "David"}
    };

    int ns = sizeof(s) / sizeof(s[0]);

    heap_sort(s, ns, sizeof(struct student), studentCgpaCmp);

    printf("Sorted students by CGPA: ");
    printStudents(s, ns);

    return 0;
}
