#include <iostream>
#include <string>
#include <vector>

using namespace std;

int charToDigit(char c) {
    return c - 'a';
}

void CountingSort(vector<string>& ans, vector<string>& arr, int len, int upperb, int index)
{
    int C[upperb+1];

    for (int i = 0; i < upperb + 1; i++)
    {
        C[i] = 0;
    }
    for (int i = 0; i < len; i++)
    {
        int temp = charToDigit(arr[i][index]);
        C[temp] += 1;
    }
    for (int i = 1; i < upperb + 1; i++)
    {
        C[i] += C[i - 1];
    }
    for (int j = len-1 ; j >= 0; j--)
    {

        int temp = charToDigit(arr[j][index]);
        C[temp] -=  1;  // Avoid repeat
        ans[C[temp]] = arr[j];

    }
}


void RadixSort(vector<string>& arr, int n, int m)
{
    vector<string> ans(n);
    for (int i = m-1; i >= 0; i--)
    {
        CountingSort(ans,arr,n,25,i);
        std::copy(ans.begin(), ans.end(), arr.begin());
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<string> arr(n);

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    RadixSort(arr,n,m);

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }

    return 0;
}
