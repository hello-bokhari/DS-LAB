//24k060 Abbad Hasan DS Lab 6
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void bubbleSort(Node* head) {
    if (head == nullptr) return;

    bool swapped;
    Node* temp;
    do {
        swapped = false;
        temp = head;
        while (temp->next != nullptr) {
            if (temp->data > temp->next->data) {
                swap(temp->data, temp->next->data);
                swapped = true;
            }
            temp = temp->next;
        }
    } while (swapped);
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
int main() {
    Node* head = new Node{4, nullptr};
    head->next = new Node{2, nullptr};
    head->next->next = new Node{1, nullptr};
    head->next->next->next = new Node{3, nullptr};
    
    cout << "Original List: ";
    printList(head);
    bubbleSort(head);
    cout << "Sorted List: ";
    printList(head);
    return 0;
}
