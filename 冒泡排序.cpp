#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

void bubbleSort(std::vector<int> &v) {
    int n = v.size();
    if (n < 2) return;
    // ����һ����־λ �ж��Ƿ����Ƚ�
    bool flag = false;
    // �ܵ����� n����ֻ��Ҫ�Ƚ�n-1��
    for (int i=n-1; i>0; --i) {
        flag = false;
        // ÿһ����Ҫ�Ĵ���Ϊi��
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

    printf("����ǰ:\n");
    for(const auto&i: v) {
        printf("%d ", i);
    }
    printf("\n");

    printf("�����:\n");
    bubbleSort(v);
    for (const auto&i: v) {
        printf("%d ", i);
    }
    printf("\n");

    return 0;
}