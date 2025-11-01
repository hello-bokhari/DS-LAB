#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int v): data(v), left(NULL), right(NULL) {}
};

void inorder(Node* node, vector<int> &vals) {
    if (!node) return;
    inorder(node->left, vals);
    vals.push_back(node->data);
    inorder(node->right, vals);
}

float findMedian(Node* root) {
    vector<int> vals;
    inorder(root, vals);
    int n = vals.size();
    if (n % 2 != 0)
        return vals[n / 2];
    else
        return (vals[n / 2 - 1] + vals[n / 2]) / 2.0;
}

int main() {
    Node* root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(15);

    cout << "Median: " << findMedian(root);
    return 0;
}
