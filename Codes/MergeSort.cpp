#include <iostream>

void merge(int arr[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[q + 1 + j];
// Set up the data.
    int i = 0, j = 0, k = p;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            k++;
            i++;
        } else {
            arr[k] = R[j];
            k++;
            j++;
        }
    }

    while (i < n1) {
        arr[k] = L[i];
        k++;
        i++;
    }

    while (j < n2) {
        arr[k] = R[j];
        k++;
        j++;
    }
}


void MergeSort(int arr[], int p, int r) {
    if (p < r) {
        int q = p + (r - p) / 2;
        MergeSort(arr, p, q);
        MergeSort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}

int main() {
    int n;
    std::cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];

    MergeSort(arr, 0, n-1);

    for (int j = 0; j < n; j++) {
        std::cout << arr[j] << " ";
    }

    return 0;
}
