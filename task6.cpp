#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class SLinkList {
public:
    Node* head;
    Node* tail;
    SLinkList() {
        head = NULL;
        tail = NULL;
    }

    void insertAtTail(int val) {
        Node* n = new Node(val);
        if (head == NULL) {
            head = n;
            tail = n;
            return;
        }
        tail->next = n;
        tail = n;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void deleteValue(int val) {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        Node* curr = head;
        Node* prev = NULL;

        while (curr != NULL && curr->data != val) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == NULL) {
            cout << "Value not present in the list.\n";
            return;
        }

        if (curr == head) {
            head = head->next;
            if (curr == tail) tail = NULL;
            delete curr;
            return;
        }

        prev->next = curr->next;
        if (curr == tail) tail = prev;
        delete curr;
    }
};

int main() {
    int arr[7] = {5, 3, 1, 8, 6, 4, 2};
    cout << "Array: ";
    for (int i = 0; i < 7; i++) cout << arr[i] << " ";
    cout << endl;

    SLinkList list;
    for (int i = 0; i < 7; i++) list.insertAtTail(arr[i]);

    cout << "Initial Linked List: ";
    list.display();

    int val;
    cout << "Enter a value to delete: ";
    cin >> val;

    list.deleteValue(val);

    cout << "Linked List after deletion: ";
    list.display();

    return 0;
}
