#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

void merge(int* arr, int low, int mid, int high) {
    int tmp[high-low+1], k = 0;
    int i=low, j=mid+1;

    while (i<=mid && j<=high) {
        tmp[k++] = arr[i]<=arr[j] ? arr[i++] : arr[j++];
    }
    while (i<=mid) {
        tmp[k++] = arr[i++];
    }
    while (j<=high) {
        tmp[k++] = arr[j++];
    }
    memcpy(arr+low, tmp, sizeof(tmp));
}

void mergeSort(int* arr, int low, int high) {
    if (low < high) {
        int mid = low + (high-low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);

        merge(arr, low, mid, high);
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

    mergeSort(arr, 0, len-1);

    printf("after: \n");
    for (int i=0; i<len; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
   