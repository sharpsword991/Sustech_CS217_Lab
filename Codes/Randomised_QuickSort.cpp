#include <iostream>
using namespace std;

int Randomised_Partition(int arr[], int p, int r)
{

    int rad = p + rand() % (r - p + 1);
//    cout << rad << endl;

    swap(arr[rad], arr[r]);
    int middle = arr[r];

    int i = p-1;
    for(int j=p ; j <= r - 1 ; j++)
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

void Randomised_QuickSort(int arr[], int p, int r)
{
    if (p < r)
    {
        int q = Randomised_Partition(arr, p, r);
        Randomised_QuickSort(arr, p, q - 1);
        Randomised_QuickSort(arr, q + 1, r);
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

    Randomised_QuickSort(arr, 0, n-1);

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
