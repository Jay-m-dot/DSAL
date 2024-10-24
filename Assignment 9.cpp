#include <iostream>
using namespace std;

void MaxHeapify(int a[], int n, int i) {
    int j, temp;
    temp = a[i];
    j = 2 * i + 1;

    while (j < n) {
        if (j + 1 < n && a[j + 1] > a[j])
            j += 1;
        if (temp >= a[j])
            break;
        else {
            a[(j - 1) / 2] = a[j];
            j = 2 * j + 1;
        }
    }
    a[(j - 1) / 2] = temp;
}

void HeapSort(int a[], int n) {
    int temp;
    for (int i = n - 1; i >= 1; i--) {
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        MaxHeapify(a, i, 0);
    }
}

void Build_MaxHeap(int a[], int n) {
    for (int i = (n / 2) - 1; i >= 0; i--) {
        MaxHeapify(a, n, i);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements to be sorted: ";
    cin >> n;
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << (i + 1) << ": ";
        cin >> arr[i];
    }
    
    Build_MaxHeap(arr, n);
    HeapSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

