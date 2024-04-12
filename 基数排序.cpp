#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

void argMax(int* arr, int len, int& maxValue) {
    for (int i=0; i<len; ++i) {
        maxValue = arr[i] > maxValue ? arr[i] : maxValue;
    }
}

void _radixSort(int* arr, int len, int exp) {
    int result[len];        // 暂存临时结果
    int bucket[10];         // 10个桶
    memset(result, 0, sizeof(result));
    memset(bucket, 0, sizeof(bucket));

    for (int i=0; i<len; ++i) {         // 记录每个桶记录末尾数的个数
        bucket[(arr[i]/exp)%10]++;
    }

    for (int i=1; i<10; ++i) {          // 精妙之处 累加刚好是len
        bucket[i] += bucket[i-1];
    }

    for (int i=len-1; i>=0; --i) {
        int iexp = (arr[i]/exp)%10;
        result[bucket[iexp]-1] = arr[i];        // 刚好是该数字所在的下标
        bucket[iexp]--;
    }

    memcpy(arr, result, sizeof(result));    // 每一轮的值拷过去
}

void radixSort(int* arr, int len) {
    int maxValue = 0;
    argMax(arr, len, maxValue);

    for (int exp=1; maxValue/exp>0; exp*=10) {
        _radixSort(arr, len, exp);
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

    radixSort(arr, len);

    printf("after: \n");
    for (const auto&i: arr) {
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}