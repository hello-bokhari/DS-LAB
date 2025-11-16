#include <iostream>
using namespace std;

#define MAX 50

class MinHeap {
private:
    int heap[MAX];
    int size;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    void heapifyUp(int i) {
        while (i > 0 && heap[parent(i)] > heap[i]) {
            int t = heap[i];
            heap[i] = heap[parent(i)];
            heap[parent(i)] = t;
            i = parent(i);
        }
    }

    void heapifyDown(int i) {
        int smallest = i;
        int l = left(i), r = right(i);

        if (l < size && heap[l] < heap[smallest]) smallest = l;
        if (r < size && heap[r] < heap[smallest]) smallest = r;

        if (smallest != i) {
            int t = heap[i];
            heap[i] = heap[smallest];
            heap[smallest] = t;
            heapifyDown(smallest);
        }
    }

public:
    MinHeap() { size = 0; }

    void insert(int val) {
        heap[size] = val;
        heapifyUp(size);
        size++;
    }

    void update_key(int i, int new_val) {
        heap[i] = new_val;
        heapifyUp(i);
        heapifyDown(i);
    }

    void deleteAt(int i) {
        heap[i] = heap[size - 1];
        size--;
        heapifyUp(i);
        heapifyDown(i);
    }

    void print() {
        for(int i = 0; i < size; i++) cout << heap[i] << " ";
        cout << endl;
    }
};

int main() {
    MinHeap h;
    h.insert(8);
    h.insert(7);
    h.insert(6);
    h.insert(5);
    h.insert(4);

    cout << "Initial Heap: ";
    h.print();

    h.update_key(2, 1);
    cout << "After update_key(2, 1): ";
    h.print();

    h.deleteAt(1);
    cout << "After deleteAt(1): ";
    h.print();
}
