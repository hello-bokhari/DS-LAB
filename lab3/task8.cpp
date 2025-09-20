#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        prev = next = NULL;
    }
};

class DList {
public:
    Node* head;
    Node* tail;
    DList() {
        head = tail = NULL;
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

    static DList concatenate(DList& L, DList& M) {
        if (!L.head) return M;
        if (!M.head) return L;

        L.tail->next = M.head;
        M.head->prev = L.tail;
        L.tail = M.tail;
        return L;
    }
};

int main() {
    DList L, M;
    L.insertAtTail(1);
    L.insertAtTail(2);
    L.insertAtTail(3);
    M.insertAtTail(4);
    M.insertAtTail(5);
    M.insertAtTail(6);

    cout << "List L: "; L.display();
    cout << "List M: "; M.display();
    DList result = DList::concatenate(L, M);
    cout << "Concatenated List: "; result.display();
    return 0;
}
