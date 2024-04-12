#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

int argMax(int* arr, int len) {
    int maxValue = -1;
    for (int i=0; i<len; ++i) {
        maxValue = arr[i] > maxValue ? arr[i] : maxValue;
    }
    return maxValue;
}

void countSort(int* arr, int len) {
    int maxValue = argMax(arr,len);
    int tmp[maxValue+1];
    memset(tmp, 0, sizeof(tmp));
    for (int i=0; i<len; ++i) {
        tmp[arr[i]]++;
    }
    for (int i=0, k=0; i<maxValue+1; ++i) {
        while (tmp[i]--) {
            arr[k++] = i;
        }
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

    countSort(arr, len);

    printf("after: \n");
    for (auto i: arr) {
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}
   