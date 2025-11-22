#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int v) { val = v; next = nullptr; }
};

class Hash {
private:
    static const int S = 10;
    Node* tab[S];
    int hashKey(int x) { return x % S; }
public:
    Hash() { for (int i = 0; i < S; i++) tab[i] = nullptr; }

    void add(int x) {
        int idx = hashKey(x);
        Node* n = new Node(x);
        n->next = tab[idx];
        tab[idx] = n;
    }

    void removeKey(int x) {
        int idx = hashKey(x);
        Node* t = tab[idx];
        Node* p = nullptr;
        while (t) {
            if (t->val == x) {
                if (p) p->next = t->next;
                else tab[idx] = t->next;
                delete t;
                return;
            }
            p = t;
            t = t->next;
        }
    }

    bool find(int x) {
        int idx = hashKey(x);
        Node* t = tab[idx];
        while (t) { if (t->val == x) return true; t = t->next; }
        return false;
    }

    void show() {
        for (int i = 0; i < S; i++) {
            cout << i << ": ";
            Node* t = tab[i];
            while (t) { cout << t->val << " "; t = t->next; }
            cout << endl;
        }
    }
};
int main() {
    Hash h;

    h.add(15);
    h.add(25);
    h.add(35);
    h.add(45);

    cout << "Initial Table:" << endl;
    h.show();
    cout << endl;

    cout << "Searching 25: ";
    cout << (h.find(25) ? "Found" : "Not Found") << endl;

    cout << "Searching 50: ";
    cout << (h.find(50) ? "Found" : "Not Found") << endl;
    cout << endl;

    cout << "Deleting 25..." << endl;
    h.removeKey(25);

    cout << "Table After Deletion:" << endl;
    h.show();
}

