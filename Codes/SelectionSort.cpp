#include <iostream>

int main()
{
    int n=0;
    std::cin >> n;
    int array[n+1];
    for(int i=1;i<=n;i++){
        std::cin >> array[i];
    }
    for(int i=1;i<=n;i++){
        int key = i;
        for(int j=i+1;j<=n;j++){
            if( array[j] < array[key]){
                key = j;
            }
        }
        int temp = array[i];
        array[i] = array[key];
        array[key] = temp;
    }
    for(int i=1;i<=n;i++){
        std::cout << array[i] << ' ';
    }
    return 0;
}
