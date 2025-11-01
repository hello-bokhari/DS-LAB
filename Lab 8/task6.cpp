#include <iostream>
using namespace std;

class Node {
public:
    int productID, quantity;
    Node* left;
    Node* right;
    Node(int id, int q): productID(id), quantity(q), left(NULL), right(NULL) {}
};

class InventoryBST {
    Node* root;
    
    Node* insert(Node* node, int id, int q) {
        if (!node) return new Node(id, q);
        if (id < node->productID)
            node->left = insert(node->left, id, q);
        else if (id > node->productID)
            node->right = insert(node->right, id, q);
        else
            node->quantity += q; // update existing
        return node;
    }

    Node* search(Node* node, int id) {
        if (!node || node->productID == id) return node;
        if (id < node->productID) return search(node->left, id);
        return search(node->right, id);
    }

    void findMax(Node* node, Node*& maxNode) {
        if (!node) return;
        if (!maxNode || node->quantity > maxNode->quantity) maxNode = node;
        findMax(node->left, maxNode);
        findMax(node->right, maxNode);
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << "Product " << node->productID << " | Qty: " << node->quantity << endl;
        inorder(node->right);
    }

public:
    InventoryBST(): root(NULL) {}
    void insert(int id, int q) { root = insert(root, id, q); }
    void display() { inorder(root); }
    void searchProduct(int id) {
        Node* res = search(root, id);
        if (res) cout << "Product found! ID: " << res->productID << ", Qty: " << res->quantity << endl;
        else cout << "Product not found.\n";
    }
    void maxQuantity() {
        Node* maxNode = NULL;
        findMax(root, maxNode);
        if (maxNode)
            cout << "Highest Quantity Product: ID " << maxNode->productID << " (" << maxNode->quantity << ")\n";
    }
};

int main() {
    InventoryBST inv;
    inv.insert(101, 50);
    inv.insert(102, 75);
    inv.insert(103, 25);
    inv.insert(104, 120);
    inv.insert(105, 60);
    cout << "Inventory List:\n";
    inv.display();
    inv.searchProduct(102);
    inv.maxQuantity();
    return 0;
}
