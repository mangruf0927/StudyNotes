#include <iostream>
#include <vector>
using namespace std;

// 삽입 정렬
void InsertionSort(vector<int>& arr)
{
    for(int i = 1; i < arr.size(); i++)
    {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
	vector<int> data = { 1, 9, 7, 4, 5, 6, 2, 10, 8, 3 };
	InsertionSort(data);

	for(int i = 0; i < data.size(); i++) cout << data[i] << " ";

	return 0;
}
