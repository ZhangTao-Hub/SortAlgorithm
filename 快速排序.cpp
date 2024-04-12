#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

int partition(int* arr, int low, int high) {
    int pivot = arr[low];
    int left = low, right = high;
    while (left<right) {
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

    quickSort(arr, 0, len-1);

    printf("after: \n");
    for (int i=0; i<len; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
   