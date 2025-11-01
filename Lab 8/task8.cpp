#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int v): data(v), left(NULL), right(NULL) {}
};

int countRange(Node* root, int a, int b) {
    if (!root) return 0;
    if (root->data >= a && root->data <= b)
        return 1 + countRange(root->left, a, b) + countRange(root->right, a, b);
    else if (root->data < a)
        return countRange(root->right, a, b);
    else
        return countRange(root->left, a, b);
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(50);
    root->left->left = new Node(1);
    root->right->left = new Node(40);
    root->right->right = new Node(100);

    int a = 5, b = 45;
    cout << "Count of nodes in range [" << a << ", " << b << "] = " << countRange(root, a, b);
    return 0;
}
