#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapfy(int* arr, int i, int n) {
    int father = i;
    int son = 2*father+1;
    while (son <= n) {
        if (son+1<=n && arr[son+1]>arr[son]) son++;
        if (arr[father] > arr[son]) return;
        swap(&arr[son], &arr[father]);
        father = son;
        son = 2*father+1;
    }
}

void heapSort(int* arr, int len) {
    for (int i=(len-1)/2; i>=0; --i) heapfy(arr, i, len-1);
    for (int i=len-1; i>0; --i) {        // 下沉
        swap(&arr[0], &arr[i]);
        heapfy(arr, 0, i-1);        // i-1代表每次排序好一个数
    }
}

int main() {
    srand(time(NULL));
    int arr[10] = {0};
    memset(arr, 0, sizeof(arr));
    int len = sizeof(arr) / sizeof(int);
    for (int i=0; i<len; ++i) {
        arr[i] = rand() % 100;
    }
    printf("before: \n");
    for(int i=0; i<len; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    heapSort(arr, len);
    printf("排序后\n");
    for (int i=0; i<len; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
   