#include <iostream>
using namespace std;

void CountingSort(int* ans, int* arr,int len, int upperb)
{
    int C[upperb+1];
    for (int i = 0; i < upperb + 1; i++)
    {
        C[i] = 0;
    }
    for (int i = 0; i < len; i++)
    {
        C[arr[i]]= C[arr[i]] + 1;
    }
    for (int i = 1; i < upperb + 1; i++)
    {
        C[i] = C[i] + C[i - 1];
    }
    for (int j = len-1 ; j >= 0; j--)
    {
        C[arr[j]] = C[arr[j]] - 1;  // Avoid repeat
        ans[C[arr[j]]] = arr[j];
    }
}

int main()
{
    int n,m; // m means the upper bound of all elements
    cin >> n;
    cin >> m;
    int arr[n], ans[n];

    for (int i = 0; i < n; i++)
    {
        ans[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    CountingSort(ans, arr, n, m);

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
