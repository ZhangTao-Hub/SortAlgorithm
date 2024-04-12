#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

void bubbleSort(std::vector<int> &v) {
    int n = v.size();
    if (n < 2) return;
    // 增加一个标志位 判断是否发生比较
    bool flag = false;
    // 总的趟数 n个数只需要比较n-1趟
    for (int i=n-1; i>0; --i) {
        flag = false;
        // 每一趟需要的次数为i次
        for (int j=0; j<i; ++j) {
            if (v[j] > v[j+1]) {
                int t = v[j];
                v[j] = v[j+1];
                v[j+1] = t;
                flag = true;
            }
        }

        if (!flag) return;
    }
}

int main() {
    srand(time(NULL));
    std::vector<int> v;
    for (int i=0; i<10; ++i) {
        v.push_back(rand() % 100);
    }

    printf("排序前:\n");
    for(const auto&i: v) {
        printf("%d ", i);
    }
    printf("\n");

    printf("排序后:\n");
    bubbleSort(v);
    for (const auto&i: v) {
        printf("%d ", i);
    }
    printf("\n");

    return 0;
}