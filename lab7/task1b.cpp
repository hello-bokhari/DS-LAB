//24k060 Abbad Hasan DS Lab 6
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* reverseList(Node* head) {
    if (head == nullptr) return nullptr;

    Node* temp = head->next;
    head->next = head->prev;
    head->prev = temp;

    if (head->prev == nullptr) {
        return head;
    }
    return reverseList(head->prev);
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node{1, nullptr, nullptr};
    head->next = new Node{2, nullptr, head};
    head->next->next = new Node{3, nullptr, head->next};
    head->next->prev = head;
    head->next->next->prev = head->next;

    cout << "Original List: ";
    printList(head);

    head = reverseList(head);

    cout << "Reversed List: ";
    printList(head);

    return 0;
}

