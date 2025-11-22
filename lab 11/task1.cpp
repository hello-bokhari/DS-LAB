#include <iostream>
using namespace std;

class Node {
public:
    string k, v;
    Node* next;
    Node(string a, string b) { k = a; v = b; next = nullptr; }
};

class HashTable {
private:
    static const int S = 10;
    Node* tab[S];
    int hashKey(string key) {
        int s = 0;
        for (char c : key) s += c;
        return s % S;
    }
public:
    HashTable() { for (int i = 0; i < S; i++) tab[i] = nullptr; }

    void insert(string k, string v) {
        int idx = hashKey(k);
        Node* n = new Node(k, v);
        n->next = tab[idx];
        tab[idx] = n;
    }

    void display() {
        for (int i = 0; i < S; i++) {
            cout << "Bucket " << i << ": ";
            Node* t = tab[i];
            while (t) { cout << "(" << t->k << "," << t->v << ") "; t = t->next; }
            cout << endl;
        }
    }
};

int main() {
    HashTable h;
    h.insert("A", "aaaaa");
    h.insert("B", "bbbbb");
    h.insert("C", "ccccc");
    h.insert("A", "zzzzz");
    h.display();
}
