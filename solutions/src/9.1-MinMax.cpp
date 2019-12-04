#include <iostream>
#include <vector>

using namespace std;

// 求最小值,时间复杂度为O(n)
int getMin(vector<int>& v) {
    if(v.size() == 1) {
        return v[0];
    }

    int min = v[0];
    for (size_t i = 1; i < v.size(); i++) {
        if(v[i] < min) {
            min = v[i];
        }
    }
    return min;
}

// 同时获取最小值和最大值，复杂度为O(n)
struct min_max_pair
{
    int min;
    int max;
};

// 同时比较元素大小，获取最大值和最小值
// 在最坏情况下，总共比较次数为 1 + 2(n-2)；最好情况下，1 + n-2
// 因此时间复杂度为O(n)
struct min_max_pair getMinMax(vector<int>& v) {
    struct min_max_pair minmax;
    
    // only one element
    if(v.size() == 1) {
        minmax.min = v[0];
        minmax.max = v[0];
    }

    // more than one element, thus initialize the min and max
    if(v[0] < v[1]) {
        minmax.min = v[0];
        minmax.max = v[1];
    } else {
        minmax.min = v[1];
        minmax.max = v[0];
    }

    // search min and max at the same time
    for (size_t i = 2; i < v.size(); i++) {
        if(v[i] < minmax.min) {
            minmax.min = v[i];
        } else if(v[i] > minmax.max){
            minmax.max = v[i];
        }
    }
    return minmax;
}

// 对输入元素成对地进行处理，
// 1.将输入元素相互比较， 
// 2.然后把较小的值与当前值比较，较大的值与当前值进行比较
// 这样没对元素只需要处理3次。
// 时间复杂度， n为奇数, 3(n-2)/2; n为偶数, 初始比较一次，然后进行3(n-2)/2此比较，所以复杂度为3n/2 -2
struct min_max_pair getMinMaxWithPair(vector<int>& v) {
    struct min_max_pair minmax;
    int i = 0;

    if(v.size() % 2 != 0) {
        minmax.min = v[0];
        minmax.max = v[0];
        i = 1; // 设置循环初始值
    } else {
        if(v[0] < v[1]) {
            minmax.min = v[0];
            minmax.max = v[1];
        } else {
            minmax.min = v[1];
            minmax.max = v[0];
        }
        i = 2;
    }

    while (i < v.size() - 1)
    {
        // 小的和小的比，大的和大的比。
        // v[i]小的话，再和当前最小值比
        if(v[i] < v[i+1]) {
            if(v[i] < minmax.min)
                minmax.min = v[i];
            if(v[i+1] > minmax.max)
                minmax.max = v[i+1];
        } else {
            if(v[i] > minmax.max)
                minmax.max = v[i];
            if(v[i+1] < minmax.min)
                minmax.min = v[i+1];
        }
        i += 2; // 每次索引要加2，因为每次都是成对地处理元素
    }
    return minmax;
}



int main(int argc, const char** argv) {
    int arr[] = {1000, 11, 445, 1, 330, 3000};
    int length = sizeof(arr)/sizeof(int);
    vector<int> vec(arr, arr + length);

    cout << "Minimum element is " << getMin(vec) << endl;
    cout << "Minimum element is " << getMinMax(vec).min << endl;
    cout << "Maximum element is " << getMinMax(vec).max << endl;
    cout << "Minimum element is " << getMinMaxWithPair(vec).min << endl;
    cout << "Maximum element is " << getMinMaxWithPair(vec).max << endl;

    return 0;
}