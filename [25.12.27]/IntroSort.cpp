#include <cmath>

void Swap(int& a, int & b)
{
    int temp = a;
    a = b;
    b = temp;
}

// --- 삽입 정렬 ---
void InsertionSort(int arr[], int left, int right)
{
    for(int i = left + 1; i <= right; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while(j >= left && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// --- 힙 정렬 ---
void heapify(int arr[], int n, int root)
{
    int cur = root;
    int left = root * 2 + 1;
    int right = root * 2 + 2;

    // 최댓값 찾기
    if(left < n && arr[left] > arr[cur]) cur = left;
    if(right < n && arr[right] > arr[cur]) cur = right;

    if(cur != root)
    {
        Swap(arr[root], arr[cur]);
        heapify(arr, n, cur);
    }
}

void HeapSort(int arr[], int left, int right)
{
    int n = right - left + 1;

    int *temp = arr + left;

    // 최초 힙 구성
    for(int i = n / 2 - 1; i >= 0; i--) heapify(temp, n, i);

    // 힙 정렬
    for(int i = n - 1; i > 0; i--)
    {
        Swap(temp[0], temp[i]);
        heapify(temp, i, 0);
    }
}

// --- 퀵 정렬 ---
int Partition(int arr[], int left, int right)
{
    int mid = (left + right) / 2;
    int pivot = arr[mid];

    int start = left;
    int end = right;

    while(start <= end)
    {
        while(arr[start] < pivot) start++;
        while(arr[end] > pivot) end--;
        if(start <= end) Swap(arr[start++], arr[end--]);
    }

    return start;
}

void QuickSort(int arr[], int left, int right, int depth)
{
    if(depth == 0)
    {
        if (right - left + 1 > 16) HeapSort(arr, left, right);
        return;
    }

    if(left < right)
    {
        int index = Partition(arr, left, right);
        QuickSort(arr, left, index - 1, depth - 1);
        QuickSort(arr, index, right, depth - 1);
    }
}

// --- 인트로 소트 ---
void IntroSort(int arr[], int n)
{
    if(n <= 16) 
    {
        InsertionSort(arr, 0, n - 1);
        return;
    }

    int limit = 2 * std::ceil(std::log2(n));
    
    QuickSort(arr, 0, n - 1, limit);
    InsertionSort(arr, 0, n - 1);
}
