//24k060 Abbad Hasan DS Lab 6
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void deleteFront(Node*& head) {
    if (head == nullptr) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteLast(Node*& head) {
    if (head == nullptr) return;
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

void deleteAtPosition(Node*& head, int position) {
    if (head == nullptr || position < 1) return;
    if (position == 1) {
        deleteFront(head);
        return;
    }
    Node* temp = head;
    for (int i = 1; temp != nullptr && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == nullptr || temp->next == nullptr) return;
    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node{1, nullptr};
    head->next = new Node{2, nullptr};
    head->next->next = new Node{3, nullptr};
    head->next->next->next = new Node{4, nullptr};
    cout << "Original List: ";
    printList(head);
    deleteFront(head);
    cout << "After deleting from front: ";
    printList(head);
    deleteLast(head);
    cout << "After deleting from last: ";
    printList(head);
    deleteAtPosition(head, 2);
    cout << "After deleting at position 2: ";
    printList(head);
    return 0;
}

