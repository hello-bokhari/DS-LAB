#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int key, height;
    Node *left, *right;
    Node(int val) : key(val), height(1), left(nullptr), right(nullptr) {}
};

class AVLTree {
private:
    int height(Node* n) { return n ? n->height : 0; }

    int getBalance(Node* n) { return n ? height(n->left) - height(n->right) : 0; }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;
        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;
        return y;
    }

    Node* insert(Node* node, int key) {
        if (!node)
            return new Node(key);
        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else
            return node;
        node->height = 1 + max(height(node->left), height(node->right));
        int balance = getBalance(node);
        if (balance > 1 && key < node->left->key)
            return rightRotate(node);
        if (balance < -1 && key > node->right->key)
            return leftRotate(node);
        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }

    void inorder(Node* root) {
        if (!root) return;
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }

    void inorderKth(Node* root, int& k, int& ans) {
        if (!root) return;
        inorderKth(root->left, k, ans);
        if (--k == 0) {
            ans = root->key;
            return;
        }
        inorderKth(root->right, k, ans);
    }

    int leftHeight(Node* root) { return root && root->left ? root->left->height : 0; }
    int rightHeight(Node* root) { return root && root->right ? root->right->height : 0; }

public:
    Node* root;
    AVLTree() : root(nullptr) {}

    void insertKey(int key) {
        root = insert(root, key);
    }

    void printInorder() {
        inorder(root);
        cout << endl;
    }

    void findKth(int k) {
        int ansSmallest = -1, ansLargest = -1;
        int n = countNodes(root);
        int ks = k, kl = n - k + 1;
        inorderKth(root, ks, ansSmallest);
        inorderKth(root, kl, ansLargest);
        cout << "\nKth Smallest: " << ansSmallest;
        cout << "\nKth Largest: " << ansLargest;
        cout << "\nLeft Height: " << leftHeight(root)
             << " | Right Height: " << rightHeight(root) << endl;
    }

    int countNodes(Node* root) {
        if (!root) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

int main() {
    AVLTree tree;
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    for (int val : values)
        tree.insertKey(val);
    cout << "Inorder traversal of AVL Tree:\n";
    tree.printInorder();
    tree.findKth(3);
    return 0;
}
