#include <iostream>
#include <vector>

using namespace std;

void swap(int* a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(vector<int>& v, int low, int high) {
    int pivot = v[high];
    int pivotIndex = low - 1;
    // 寻找正确的pivot index的位置
    // 结束条件到hight-1, pivot的值不参比较，只用做最后的一次交换
    for (size_t i = low; i <= high - 1; i++) {
        if(v[i] <= pivot) {
            pivotIndex++;
            swap(&v[pivotIndex], &v[i]);
        }
    }
    // 找到之后将pivot的值与正确pivot index位置上的值交换
    swap(&v[pivotIndex + 1], &v[high]);
    return pivotIndex + 1;
    
}

// 选择问题-randomized-select, 选择数组v[p..r]中第i小的元素
int quickselect(vector<int>& v, int p, int r, int i) {
    if(p == r) {
        return v[p];
    }
    
    // 分区函数partition将数组v[p..r]划分为子数组v[p..q-1]和v[q+1,r],
    // 使得子数组v[p..q-1]中的每个元素小于等于v[q],并且v[q]小于子数组v[q+1,r]中的每个元素
    // 即满足 v[p..q-1] <= v[q] < v[q+1,r]
    int q = partition(v, p, r);
    
    // 计算子数组v[p..q]的元素个数k，即处于划分的低区域的元素个数加1，这个1表示主元v[q]
    // 即当前分区后小于等于v[q]的个数
    int k = q - p + 1;

    if(i == k) {
        return v[q];
    }
    else if(i < k) {
        return quickselect(v, p, q - 1, i);
    } else {
        return quickselect(v, q + 1, r, i - k);
    }
}


int main(int argc, const char** argv) {
    int arr[] = {1000, 11, 445, 1, 330, 3000};
    int length = sizeof(arr)/sizeof(int);
    vector<int> vec(arr, arr + length);

    cout << "array length is " << length << endl;
    cout << "k'th smallest is " << quickselect(vec, 0, length-1, 6) << endl;
    
    return 0;
}