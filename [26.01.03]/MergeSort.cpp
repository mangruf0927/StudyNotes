#include <iostream>
using namespace std;

// > : 기본 Merge Sort
void MergeBasic(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int * L = new int[n1];
    int * R = new int[n2];

    for(int i = 0; i < n1; i++) L[i] = arr[left + i];
    for(int i = 0; i < n2; i++) R[i] = arr[mid + i + 1];

    int i = 0, j = 0;
    int k = left;

    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while(i < n1) arr[k++] = L[i++];
    while(j < n2) arr[k++] = R[j++];

    delete [] L;
    delete [] R;
}

void MergeSortBasic(int arr[], int left, int right)
{
    if(left >= right) return;
    int mid = (left + right) / 2;

    // 분할
    MergeSortBasic(arr, left, mid);
    MergeSortBasic(arr, mid + 1, right);
    
    // 정복
    MergeBasic(arr, left, mid, right);
}

// > : temp 배열 재사용 Merge Sort
void Merge(int arr[], int temp[], int left, int mid, int right)
{
    int i = left, j = mid + 1;
    int k = left;

    while(i <= mid && j <= right)
    {
        if(arr[i] <= arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }

    while(i <= mid) temp[k++] = arr[i++];
    while(j <= right) temp[k++] = arr[j++];

    for(int i = left; i <= right; i++) arr[i] = temp[i];
}

void MergeSort(int arr[], int temp[], int left, int right)
{
    if(left >= right) return;
    int mid = (left + right) / 2;

    MergeSort(arr, temp, left, mid);
    MergeSort(arr, temp, mid + 1, right);
    
    Merge(arr, temp, left, mid, right);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr); 

    int data[] = { 1, 9, 7, 4, 5, 6, 2, 10, 8, 3 };
    int data2[] = { 1, 9, 7, 4, 5, 6, 2, 10, 8, 3 };
    int n = sizeof(data) / sizeof(data[0]);
    int * temp = new int[n];

    MergeSortBasic(data, 0, n - 1);
    MergeSort(data2, temp, 0, n - 1);

    for(int i = 0; i < n; i++)
        cout << data[i] << " ";

    cout << "\n";
    for(int i = 0; i < n; i++)
        cout << data2[i] << " ";

    delete [] temp;
    return 0; 
} 