#include <iostream>
using namespace std;

class Node {
public:
    string w, m;
    Node* next;
    Node(string a, string b) { w = a; m = b; next = nullptr; }
};

class Dict {
private:
    static const int S = 100;
    Node* tab[S];
    int keyHash(string x) {
        int s = 0;
        for (char c : x) s += c;
        return s % S;
    }
public:
    Dict() { for (int i = 0; i < S; i++) tab[i] = nullptr; }

    void add(string w, string m) {
        int idx = keyHash(w);
        Node* n = new Node(w, m);
        n->next = tab[idx];
        tab[idx] = n;
    }

    void find(string w) {
        int idx = keyHash(w);
        Node* t = tab[idx];
        while (t) {
            if (t->w == w) { cout << w << ": " << t->m << endl; return; }
            t = t->next;
        }
        cout << "Not found" << endl;
    }

    void removeKey(string w) {
        int idx = keyHash(w);
        Node* t = tab[idx];
        Node* p = nullptr;
        while (t) {
            if (t->w == w) {
                if (p) p->next = t->next;
                else tab[idx] = t->next;
                delete t;
                cout << "Deleted " << w << endl;
                return;
            }
            p = t;
            t = t->next;
        }
        cout << "Not found" << endl;
    }

    void show() {
        for (int i = 0; i < S; i++) {
            if (tab[i]) {
                cout << i << ": ";
                Node* t = tab[i];
                while (t) { cout << "(" << t->w << "," << t->m << ") "; t = t->next; }
                cout << endl;
            }
        }
    }
};
int main() {
    Dict d;

    d.add("AB", "FASTNU");
    d.add("CD", "CS");
    d.add("EF", "AI");
    d.add("XY", "Math");

    cout << "Dictionary:" << endl;
    d.show();
    cout << endl;

    cout << "Searching AB: ";
    d.find("AB");
    cout << endl;

    cout << "Deleting EF..." << endl;
    d.removeKey("EF");
    cout << endl;

    cout << "Dictionary after deletion:" << endl;
    d.show();
}

