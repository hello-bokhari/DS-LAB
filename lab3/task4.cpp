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
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void sortEvenODD(){
        if (head == NULL || head->next == NULL) return;

        Node* evenHead = NULL;
        Node* evenTail = NULL;
        Node* oddHead = NULL;
        Node* oddTail = NULL;

        Node* curr = head;

        while (curr != NULL) {
            if (curr->data % 2 == 0) {
                if (evenHead == NULL) {
                    evenHead = curr;
                    evenTail = curr;
                } else {
                    evenTail->next = curr;
                    evenTail = curr;
                }
            } else {
                if (oddHead == NULL) {
                    oddHead = curr;
                    oddTail = curr;
                } else {
                    oddTail->next = curr;
                    oddTail = curr;
                }
            }
            curr = curr->next;
        }

        if (evenHead == NULL || oddHead == NULL) return;

        evenTail->next = oddHead;
        oddTail->next = NULL;

        head = evenHead;
        tail = oddTail;
    }
};
int main() {
    int arr[10] = {17,15,8,12,10,5,4,1,7,6};
    cout << "Array: ";
    for (int i = 0; i < 10; i++) cout << arr[i] << " ";
    cout << endl;
    SLinkList list1;
    for (int i = 0; i < 10; i++) list1.insertAtTail(arr[i]);
    cout << "Initial Linked List: ";
    list1.display();
    list1.sortEvenODD();
    cout << "Modified Linked List: ";
    list1.display();
    


    return 0;
}