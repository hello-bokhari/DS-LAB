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
    void insertNode(int pos, int val) {
        Node* n = new Node(val);
        if (pos == 0) {
            n->next = head;
            head = n;
            if (tail == NULL) tail = n;
            return;
        }
        Node* curr = head;
        Node* pre = NULL;
        for (int i = 0; i < pos; i++) {
            if (curr == NULL) {
                cout << "Position out of bounds\n";
                delete n;
                return;
            }
            pre = curr;
            curr = curr->next;
        }
        pre->next = n;
        n->next = curr;
        if (n->next == NULL) tail = n;
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
    void insertAtStart(int val) {
        Node* n = new Node(val);
        n->next = head;
        head = n;
        if (tail == NULL) tail = n;
    }
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void deleteAtEnd() {
        if (head == NULL) return;
        if (head == tail) {
            delete head;
            head = tail = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next != tail) temp = temp->next;
        delete tail;
        tail = temp;
        tail->next = NULL;
    }
    void deleteAtFront() {
        if (head == NULL) return;
        Node* temp = head;
        head = head->next;
        if (head == NULL) tail = NULL;
        delete temp;
    }
    void deleteAfter(int pos) {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        Node* curr = head;
        for (int i = 0; i < pos; i++) {
            if (curr == NULL || curr->next == NULL) {
                cout << "Position out of bounds.\n";
                return;
            }
            curr = curr->next;
        }
        Node* toDelete = curr->next;
        if (toDelete == NULL) {
            cout << "No node to delete after the given position.\n";
            return;
        }
        curr->next = toDelete->next;
        if (toDelete == tail) tail = curr;
        delete toDelete;
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
    
    int n;
    cout<<"Enter no:";
    cin>>n;

    for(int i = 0; i < n; i++) list.insertAtTail(arr[i]);
    for(int i = 0; i < n; i++) list.deleteAtFront();
    cout << "Linked List: ";
    list.display();

    return 0;
}