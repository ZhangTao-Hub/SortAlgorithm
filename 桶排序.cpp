#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

int partition(int* arr, int low, int high) {
    int pivot = arr[low];
    int left = low, right = high;
    while (left < right) {
        while (left<right && arr[right]>=pivot) right--;
        arr[left] = arr[right];

        while (left<right && arr[left]<=pivot) left++;
        arr[right] = arr[left];
    }
    arr[left] = pivot;
    return left;
}

void quickSort(int* arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

void bucketSort(int* arr, int len) {
    int bucket[len][len];
    int bucketSize[len];

    memset(bucket, 0, sizeof(bucket));
    memset(bucketSize, 0,sizeof(bucketSize));

    for (int i=0; i<len; ++i) {
        bucket[arr[i]/10][bucketSize[arr[i]/10]++] = arr[i];
    }

    // 对每个桶调用一次排序算法
    for (int i=0; i<len; ++i) {
        quickSort(bucket[i], 0, bucketSize[i]-1);
    }

    for(int i=0, k=0; i<len; ++i) {
        for (int j=0; j<bucketSize[i]; ++j) {
            arr[k++] = bucket[i][j];
        }
    }
}

int main() {

    srand(time(NULL));
    int arr[10];
    int len = sizeof(arr) / sizeof(int);
    memset(arr, 0, sizeof(arr));
    for (int i=0; i<len; ++i) {
        arr[i] = rand() % 100;
    }
    printf("before: \n");
    for (const auto&i: arr) {
        printf("%d ", i);
    }
    printf("\n");
    bucketSort(arr, len);
    printf("after: \n");
    for (const auto&i: arr) {
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}