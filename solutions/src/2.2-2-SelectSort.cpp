#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> &v) {
    for (decltype(v.size()) i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int findMin(vector<int> &v) {
    int si = 0;
    for (decltype(v.size()) i = 1; i < v.size(); ++i) {
        if (v[i] < v[si]) {
            si = i;
        }
    }
    return si;
}

/*
pseudo:
for i=1 to A.length-1
	low=i-1
	for j=i to A.length
		if A[j] < A[low]
			low=j
	swap(A[i-1],A[low])
*/

void selectSort(vector<int> &v) {
    for (int i = 1; i < v.size() - 1; ++i) {
        int si = i - 1;
		// find index of the most smaller element and swap it with index 0
		for (int j = i + 1; j < v.size(); ++j) {
            if (v[j] < v[si]) {
                si = j;
            }
        }
		
        swap(&v[i - 1], &v[si]);
    }
}

int main() {
    int arr[] = {6, 4, 5, 2, 3, 1};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(int));


    cout << "min of array: " << v[findMin(v)] << endl;
    selectSort(v);

    print(v);
    return 0;
}