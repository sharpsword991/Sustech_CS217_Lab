#include <iostream>
using namespace std;

int Partition(int arr[], int p, int r)
{
    int middle = arr[r];
    int i = p-1;
    for(int j = p ; j <= r - 1 ; j++)
    {
        if(arr[j] <= middle)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[r]);
    return i+1;
}
void QuickSort(int arr[], int p, int r)
{
    if (p < r)
    {
        int q = Partition(arr, p, r);
        QuickSort(arr, p, q - 1);
        QuickSort(arr, q + 1, r);
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    QuickSort(arr, 0, n-1);

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
