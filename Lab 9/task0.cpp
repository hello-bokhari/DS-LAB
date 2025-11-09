struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int val) : key(val), left(nullptr), right(nullptr) {}
};

Node* sortedArrayToAVL(vector<int>& arr, int start, int end) {
    if (start > end) return nullptr;

    int mid = (start + end) / 2;
    Node* root = new Node(arr[mid]);
    root->left = sortedArrayToAVL(arr, start, mid - 1);
    root->right = sortedArrayToAVL(arr, mid + 1, end);
    return root;
}

Node* convertBSTtoAVL(Node* root) {
    vector<int> inorder;
    function<void(Node*)> inorderTraversal = [&](Node* node) {
        if (!node) return;
        inorderTraversal(node->left);
        inorder.push_back(node->key);
        inorderTraversal(node->right);
    };
    inorderTraversal(root);
    return sortedArrayToAVL(inorder, 0, inorder.size() - 1);
}
