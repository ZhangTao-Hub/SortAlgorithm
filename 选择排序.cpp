#include <ctime>
#include <cstdlib>
#include <vector>

void selectSort(std::vector<int>& v) {
    if (v.size() < 2) return;
    int minPos = 0;
    for (int i=0; i<v.size()-1; ++i) {
        minPos = i;
        for (int j=i+1; j<v.size(); ++j) {
            if (v[j] < v[minPos]) {
                minPos = j;
            }
        }
        if (minPos != i) {
            int t = v[minPos];
            v[minPos] = v[i];
            v[i] = t;
        }
    }
}

void selectSort2(std::vector<int>& v) {
    int l = 0, r = v.size()-1;
    int minPos = 0, maxPos = 0;
    while (l < r) {
        minPos = maxPos = l;
        for(int i=l; i<=r; ++i) {
            if (v[i] < v[minPos]) minPos = i;
            if (v[i] > v[maxPos]) maxPos = i;
        }
        if (minPos != l) {
            int t = v[minPos];
            v[minPos] = v[l];
            v[l] = t;
        }

        // 若最左侧是最大数时，此时最大数位置已被换走
        if (maxPos == l) maxPos = minPos;

        if (maxPos != r) {
            int t = v[maxPos];
            v[maxPos] = v[r];
            v[r] = t;
        }

        ++l;
        --r;
    }
}

int main() {

    srand(time(nullptr));
    std::vector<int> v;
    for (int i=0; i<10; ++i) {
        v.push_back(rand() % 100);
    }

    printf("排序前\n");
    for (const auto& i:v) {
        printf("%d ", i);
    }
    printf("\n");

    // selectSort(v);
    selectSort2(v); // 优化后, 一次确定两个数

    printf("排序后\n");
    for (const auto&i: v) {
        printf("%d ", i);
    }
    return 0;
}