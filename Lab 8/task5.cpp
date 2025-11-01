#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int v): data(v), left(NULL), right(NULL) {}
};

bool isBST(Node* node, int minVal, int maxVal) {
    if (!node) return true;
    if (node->data <= minVal || node->data >= maxVal) return false;
    return isBST(node->left, minVal, node->data) && isBST(node->right, node->data, maxVal);
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(3);
    root->left->right = new Node(8);

    cout << (isBST(root, INT_MIN, INT_MAX) ? "It is a BST" : "Not a BST");
    return 0;
}
