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

class LinkedList {
public:
    Node* head;
    LinkedList() { head = NULL; }

    void insertAtTail(int val) {
        Node* n = new Node(val);
        if (head == NULL) {
            head = n;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = n;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void rearrange() {
        if (!head || !head->next) return;
        Node* odd = head;
        Node* even = head->next;
        Node* evenHead = even;
        while (odd->next && even->next) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = NULL;
        Node* prev = NULL;
        Node* curr = evenHead;
        Node* next = NULL;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        Node* reversedEvenHead = prev;
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = reversedEvenHead;
    }
};

int main() {
    LinkedList list;
    int arr[] = {10,4,9,1,3,5,9,4};
    for (int x : arr) list.insertAtTail(x);
    cout << "Original List: ";
    list.display();
    list.rearrange();
    cout << "Modified List: ";
    list.display();
    return 0;
}
