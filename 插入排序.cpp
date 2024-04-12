#include <cstdio>
#include <ctime>
#include <cstdlib>


void insertSort(int arr[], int n) {
    int i=0, j=0;
    for (i=1; i<n; ++i) {
        int tmp = arr[i];       //记录待插入值
        for (j=i-1; (j>=0)&&(arr[j]>tmp); --j) {
            arr[j+1] = arr[j];  //从后往前 覆盖查找
        }
        arr[j+1] = tmp;
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
    insertSort(arr, n);
    printf("after:\n");
    for (int i=0; i<n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}