#include <iostream>
#include <vector>

using namespace std;

void swap(int* a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// https://www.geeksforgeeks.org/quick-sort/
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

void quicksort(vector<int>& v, int low, int high) {
    int pivotIndex = 0;
    if (low < high) {
        pivotIndex = partition(v, low, high);
        quicksort(v, low, pivotIndex - 1);
        quicksort(v, pivotIndex + 1, high);
    }
}

void print(vector<int> &v) {
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}


int main(int argc, const char** argv) {
    int arr[] = {1000, 11, 445, 1, 330, 3000};
    int length = sizeof(arr)/sizeof(int);
    vector<int> vec(arr, arr + length);

    cout << "array length is " << length << endl;

    quicksort(vec, 0, length-1);
    print(vec);
    
    return 0;
}