#include <iostream>
using namespace std;

bool isHeap(int arr[], int n) {
    for (int i = 0; i <= (n - 2) / 2; i++) {
        if (arr[i] > arr[2*i+1]) return false;
        if (2*i+2 < n && arr[i] > arr[2*i+2]) return false;
    }
    return true;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if(l < n && arr[l] > arr[largest]) largest = l;
    if(r < n && arr[r] > arr[largest]) largest = r;

    if(largest != i) {
        int t = arr[i];
        arr[i] = arr[largest];
        arr[largest] = t;
        heapify(arr, n, largest);
    }
}

void sortAscending(int arr[], int n) {
    for(int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for(int i = n - 1; i >= 1; i--) {
        int t = arr[0];
        arr[0] = arr[i];
        arr[i] = t;
        heapify(arr, i, 0);
    }
}

int main(){
    int arr[] = {4,5,6,8,7};
    int n = 5;

    if(isHeap(arr, n)) cout << "IS HEAP"<< endl;
    else  cout << "NOT HEAP"<< endl;

    sortAscending(arr, n);

    for(int i=0;i<n;i++)
        cout << arr[i] << " ";
}
