#include <bits/stdc++.h>
using namespace std;

#define io ios::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

int n, invention = 0;
const int Max = 2147483647;

void Merge(vector<int> &Array, int front, int mid, int end){

    // �Q�� std::vector ��constructor, 
    // ��array[front]~array[mid]��i LeftSub[]
    // ��array[mid+1]~array[end]��i RightSub[]
    vector<int> LeftSub(Array.begin()+front, Array.begin()+mid+1),
                RightSub(Array.begin()+mid+1, Array.begin()+end+1);

    LeftSub.insert(LeftSub.end(), Max);      // �bLeftSub[]���ݥ[�J�Ȭ� Max ������
    RightSub.insert(RightSub.end(), Max);    // �bRightSub[]���ݥ[�J�Ȭ� Max ������

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
                                         // front�Pend���x�}�d��
    if (front < end) {                   // ��ܥثe���x�}�d��O���Ī�
        int mid = (front+end)/2;         // mid�Y�O�N�x�}��b����index
        MergeSort(array, front, mid);    // �~��divide�x�}���e�b�qsubarray
        MergeSort(array, mid+1, end);    // �~��divide�x�}����b�qsubarray
        Merge(array, front, mid, end);   // �N���subarray�����, �æX�֥X�Ƨǫ᪺�x�}
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

