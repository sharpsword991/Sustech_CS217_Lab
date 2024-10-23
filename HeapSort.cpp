#include <iostream>
using namespace std;

void Heaplify(int arr[], int i, int n)
{
    int largest;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if ( l <=  n-1  && arr[l] > arr[i] )
    {
        largest = l;
    }
    else
    {
        largest = i;
    }
    //for left side
    if ( r <=  n-1 && arr[r] > arr[largest] )
    {
        largest = r;
    }
    //for right side
    if ( largest != i )
    {
        swap(arr[i], arr[largest]);
        Heaplify(arr, largest, n);
    }
}

void BuildHeap(int arr[], int n)
{
    for (int i=n/2-1 ; i>=0 ;i--)
    {
        Heaplify(arr, i , n);
    }
}

void heap_sort(int arr[], int n)
{
    BuildHeap(arr, n);

    for(int i = n-1; i>=1; i--)
    {
        swap(arr[0], arr[i]);
        Heaplify(arr, 0, i);
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    heap_sort(arr,n);

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
