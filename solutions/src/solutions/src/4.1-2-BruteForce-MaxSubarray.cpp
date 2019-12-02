#include <iostream>
#include <vector>

using namespace std;


int maxSubarray(vector<int> &v) {
    if (v.size() < 2)
        return -1;

    int i, j;
	// 记录的最大的子数组和
    int totalMax = INT32_MIN;
	
    for (i = 0; i < v.size(); ++i) {
        int curSum = v[i];
        for (j = i + 1; j < v.size(); j++) {
            curSum = curSum + v[j];

            if(totalMax < curSum) {
                totalMax = curSum;
                //cout << i << ", " << j << ", " << totalMax << endl;
            }
        }
    }
    
    return totalMax;
}

int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(int));

    cout << maxSubarray(v) << endl;
    return 0;
}