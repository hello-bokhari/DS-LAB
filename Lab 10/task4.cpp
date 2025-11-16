
#include <iostream>
using namespace std;

void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;

    if(l < n && arr[l] > arr[largest]) largest = l;
    if(r < n && arr[r] > arr[largest]) largest = r;

    if(largest != i) {
        int t = arr[i];
        arr[i] = arr[largest];
        arr[largest] = t;
        maxHeapify(arr, n, largest);
    }
}

void convertToMaxHeap(int arr[], int n) {
    for(int i = n/2-1; i >= 0; i--)
        maxHeapify(arr, n, i);
}

int main() {
    int arr[] = {3,5,9,6,8,20,10,12,18,9};
    int n = 10;

    convertToMaxHeap(arr, n);

    for(int i=0;i<n;i++) cout << arr[i] << " ";
}
