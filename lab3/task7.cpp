#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node() {
        data = 0;
        next = NULL;
    }
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Circular {
public:
    Node* head;
    Node* tail;

    Circular() {
        head = NULL;
        tail = NULL;
    }

    void insertAtEnd(int val) {
        Node* n = new Node(val);
        if (head == NULL) {
            head = n;
            tail = n;
            tail->next = head;
        } else {
            tail->next = n;
            tail = n;
            tail->next = head;
        }
    }

    void insertAtFront(int val) {
        Node* n = new Node(val);
        if (head == NULL) {
            head = n;
            tail = n;
            tail->next = head;
        } else {
            n->next = head;
            head = n;
            tail->next = head;
        }
    }

    void insertAtAnyPosition(int pos, int val) {
        if (pos == 0) {
            insertAtFront(val);
            return;
        }
        Node* n = new Node(val);
        Node* curr = head;
        for (int i = 0; i < pos - 1; i++) {
            if (curr->next == head) {
                cout << "Position out of bounds" << endl;
                delete n;
                return;
            }
            curr = curr->next;
        }
        n->next = curr->next;
        curr->next = n;
        if (curr == tail) tail = n;
    }
    void display() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
    void deleteByValue(int val) {
        if (head == NULL) return;

        if (head == tail && head->data == val) {
            delete head;
            head = tail = NULL;
            return;
        }

        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            tail->next = head;
            delete temp;
            return;
        }

        Node* curr = head;
        Node* prev = NULL;
        do {
            prev = curr;
            curr = curr->next;
            if (curr->data == val) {
                prev->next = curr->next;
                if (curr == tail) tail = prev;
                delete curr;
                return;
            }
        } while (curr != head);

        cout << "Value " << val << " not found in the list." << endl;
    }

};
int main() {
    Circular cll;

    cout << "Inserting at end (10, 20):" << endl;
    cll.insertAtEnd(10);
    cll.insertAtEnd(20);
    cll.display();
    cout << "Inserting at front (5):" << endl;
    cll.insertAtFront(5);
    cll.display();
    cout << "Inserting at position 1 (15):" << endl;
    cll.insertAtAnyPosition(1, 15);
    cll.display();
    cout << "Deleting node with value 20:" << endl;
    cll.deleteByValue(20);
    cll.display();
    cout << "Final Circular Linked List:" << endl;
    cll.display();

    return 0;
}


