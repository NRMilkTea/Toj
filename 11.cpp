#include <bits/stdc++.h>
using namespace std;

#define io ios::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

int n, invention = 0;
const int Max = 2147483647;

void Merge(vector<int> &Array, int front, int mid, int end){

    // 利用 std::vector 的constructor, 
    // 把array[front]~array[mid]放進 LeftSub[]
    // 把array[mid+1]~array[end]放進 RightSub[]
    vector<int> LeftSub(Array.begin()+front, Array.begin()+mid+1),
                RightSub(Array.begin()+mid+1, Array.begin()+end+1);

    LeftSub.insert(LeftSub.end(), Max);      // 在LeftSub[]尾端加入值為 Max 的元素
    RightSub.insert(RightSub.end(), Max);    // 在RightSub[]尾端加入值為 Max 的元素

    int idxLeft = 0, idxRight = 0;

    for (int i = front; i <= end; i++) {

        if (LeftSub[idxLeft] <= RightSub[idxRight] ) {
            Array[i] = LeftSub[idxLeft];
            idxLeft++;
            invention += idxRight;
        }
        else{
            Array[i] = RightSub[idxRight];
            idxRight++;
        }
    }
}

void MergeSort(vector<int> &array, int front, int end){
                                         // front與end為矩陣範圍
    if (front < end) {                   // 表示目前的矩陣範圍是有效的
        int mid = (front+end)/2;         // mid即是將矩陣對半分的index
        MergeSort(array, front, mid);    // 繼續divide矩陣的前半段subarray
        MergeSort(array, mid+1, end);    // 繼續divide矩陣的後半段subarray
        Merge(array, front, mid, end);   // 將兩個subarray做比較, 並合併出排序後的矩陣
    }
}

int main(){ //io;
	vector<int> arr;
	cin >> n;
	arr.resize(n);
	for(int i=0; i<n; i++) cin >> arr[i];
	MergeSort(arr, 0, n-1);
	cout << invention << endl;
	
	return 0;
}

