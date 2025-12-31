#include <iostream>
#include <vector>
using namespace std;

int Partition(vector<int>& arr, int left, int right)
{
    int mid = (left + right) / 2;
    int pivot = arr[mid];

    int start = left;
    int end = right;

    while(start <= end)
    {
        while(arr[start] < pivot) start++;
        while(arr[end] > pivot) end--;
        if(start <= end)
        {
            std::swap(arr[start++], arr[end--]);
        }
    }

    return start;
}

void QuickSort(vector<int>& arr, int left, int right)
{
    if(left < right)
    {
        int index = Partition(arr, left, right);
        QuickSort(arr, left, index - 1);
        QuickSort(arr, index, right);
    }
}

int main()
{
	vector<int> data = { 1, 9, 7, 4, 5, 6, 2, 10, 8, 3 };
	QuickSort(data, 0, data.size() - 1);

	for(int i = 0; i < data.size(); i++) cout << data[i] << " ";

	return 0;
}
