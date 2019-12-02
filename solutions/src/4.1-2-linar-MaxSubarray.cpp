#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> &v) {
    for (decltype(v.size()) i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int maxSubarray_linar(vector<int> &v) {
    if (v.size() < 2)
        return -1;

    int curMax = v[0];
    int maxTotal = v[0];
    for (int i = 1; i < v.size(); ++i) {
        curMax = max(curMax + v[i], v[i]);
        maxTotal = max(maxTotal,curMax);
    }

    return maxTotal;
}

int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(int));

    cout << maxSubarray_linar(v) << endl;
    print(v);
    return 0;
}