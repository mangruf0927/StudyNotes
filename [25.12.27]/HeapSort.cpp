#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void heapify(vector<int>& arr, int n, int root)
{
    int cur = root;
    int left = root * 2 + 1;
    int right = root * 2 + 2;

    // 최댓값 찾기
    if(left < n && arr[left] > arr[cur]) cur = left;
    if(right < n && arr[right] > arr[cur]) cur = right;

    if(cur != root)
    {
        swap(arr[root], arr[cur]);
        heapify(arr, n, cur);
    }
}

void HeapSort(vector<int>& arr)
{
    int n = arr.size();

    // 최초 힙 구성
    for(int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);

    // 힙 정렬
    for(int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{
	vector<int> data = { 1, 9, 7, 4, 5, 6, 2, 10, 8, 3 };
	HeapSort(data);

	for(int i = 0; i < data.size(); i++) cout << data[i] << " ";

	return 0;
}
