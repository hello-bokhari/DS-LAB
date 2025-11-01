#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Student {
public:
    string name;
    int roll;
    int score;
    Student(string n="", int r=0, int s=0) : name(n), roll(r), score(s) {}
};

class Node {
public:
    Student data;
    Node* left;
    Node* right;
    Node(Student s) : data(s), left(NULL), right(NULL) {}
};

class BST {
    Node* root;
    
    Node* insert(Node* node, Student s) {
        if (!node) return new Node(s);
        if (s.name < node->data.name)
            node->left = insert(node->left, s);
        else
            node->right = insert(node->right, s);
        return node;
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data.name << " (" << node->data.roll << ", " << node->data.score << ")\n";
        inorder(node->right);
    }

    Node* search(Node* node, string name) {
        if (!node || node->data.name == name) return node;
        if (name < node->data.name)
            return search(node->left, name);
        else
            return search(node->right, name);
    }

    Node* findMin(Node* node) {
        while (node && node->left) node = node->left;
        return node;
    }

    Node* deleteLowScores(Node* node) {
        if (!node) return NULL;
        node->left = deleteLowScores(node->left);
        node->right = deleteLowScores(node->right);
        if (node->data.score < 10) {
            if (!node->left) return node->right;
            if (!node->right) return node->left;
            Node* minNode = findMin(node->right);
            node->data = minNode->data;
            node->right = deleteLowScores(node->right);
        }
        return node;
    }

    void findMaxScore(Node* node, Student &maxS) {
        if (!node) return;
        if (node->data.score > maxS.score) maxS = node->data;
        findMaxScore(node->left, maxS);
        findMaxScore(node->right, maxS);
    }

public:
    BST() : root(NULL) {}

    void insert(Student s) { root = insert(root, s); }
    void display() { inorder(root); }
    void deleteLowScores() { root = deleteLowScores(root); }
    void searchStudent(string name) {
        Node* res = search(root, name);
        if (res)
            cout << "Found: " << res->data.name << " with score " << res->data.score << endl;
        else
            cout << "Student not found.\n";
    }
    void maxScoreStudent() {
        Student maxS("", 0, -1);
        findMaxScore(root, maxS);
        cout << "Highest Score: " << maxS.name << " (" << maxS.score << ")\n";
    }
};

int main() {
    BST tree;
    Student arr[10] = {
        {"Ali", 1, 12}, {"Zain", 2, 8}, {"Sara", 3, 15}, {"Hina", 4, 9},
        {"Ahmed", 5, 20}, {"Usman", 6, 5}, {"Nida", 7, 18}, {"Taha", 8, 25},
        {"Omer", 9, 7}, {"Mina", 10, 13}
    };

    for (int i = 0; i < 7; i++) tree.insert(arr[i]);
    cout << "\nInitial Students:\n"; tree.display();

    cout << "\nSearching for 'Sara':\n"; tree.searchStudent("Sara");

    cout << "\nDeleting students with score < 10...\n";
    tree.deleteLowScores();

    cout << "\nUpdated Students:\n"; tree.display();

    tree.maxScoreStudent();
    return 0;
}
