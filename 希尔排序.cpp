#include <cstdio>
#include <ctime>
#include <cstdlib>


void shellSort(int arr[], int n, int step) {
    int i=0, j=0;
    // 插入排序即可
    for (i=step; i<n; ++i) {
        int tmp = arr[i];
        for (j=i-step; j>=0&&arr[j]>tmp; j-=step) {
            arr[j+step] = arr[j];
        }
        arr[j+step] = tmp;
    }     
}

void shell(int arr[], int n) {
    // shell step
    for (int step=n/2; step>0; step/=2) {
        shellSort(arr, n, step);
    }
}

int main() {
    srand(time(NULL));
    int arr[10] = {0};
    int n = sizeof(arr) / sizeof(int);
    for (int i=0; i<n; ++i) {
        arr[i] = rand() % 100;
    }
    printf("before:\n");
    for (int i=0; i<n; ++i){
        printf("%d ", arr[i]);
    }
    printf("\n");
    shell(arr, n);
    printf("after:\n");
    for (int i=0; i<n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}