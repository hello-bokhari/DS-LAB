#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class BST {
    Node* root;

    Node* insert(Node* node, int val) {
        if (!node) return new Node(val);
        if (val < node->data) node->left = insert(node->left, val);
        else if (val > node->data) node->right = insert(node->right, val);
        return node;
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    bool search(Node* node, int val) {
        if (!node) return false;
        if (node->data == val) return true;
        if (val < node->data) return search(node->left, val);
        return search(node->right, val);
    }

public:
    BST() : root(NULL) {}
    void insert(int val) { root = insert(root, val); }
    void print() { inorder(root); cout << endl; }
    void searchOrInsert(int val) {
        if (search(root, val))
            cout << val << " already exists in BST.\n";
        else {
            insert(val);
            cout << val << " inserted.\n";
            print();
        }
    }
};

int main() {
    BST t;
    t.insert(10); t.insert(5); t.insert(15); t.insert(3);
    t.print();
    int val;
    cout << "Enter value to search or insert: ";
    cin >> val;
    t.searchOrInsert(val);
    return 0;
}
