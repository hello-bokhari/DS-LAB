#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* next;

    Node(char val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    void insert(char val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;

        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    bool isPalindrome() {
        if (!head || !head->next) return true;

        Node* slow = head;
        Node* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node* secondHalf = reverse(slow->next);
        Node* firstHalf = head;
        Node* checkHalf = secondHalf;
        bool palindrome = true;

        while (checkHalf) {
            if (firstHalf->data != checkHalf->data) {
                palindrome = false;
                break;
            }
            firstHalf = firstHalf->next;
            checkHalf = checkHalf->next;
        }

        slow->next = reverse(secondHalf);
        return palindrome;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << " -> ";
            temp = temp->next;
        }
        cout << " -> NULL" << endl;
    }
};

int main() {
    LinkedList list1;
    list1.insert('1');
    list1.insert('0');
    list1.insert('2');
    list1.insert('0');
    list1.insert('1');

    cout << "List: ";
    list1.display();

    if (list1.isPalindrome()) {
        cout << "Palindrome\n";
    } else {
        cout << "NOT Palindrome\n";
    }

    LinkedList list2;
    char word[] = {'B','O','R','R','O','W','O','R','R','O','B'};
    for (char c : word) {
        list2.insert(c);
    }

    cout << "List: ";
    list2.display();

    if (list2.isPalindrome()) {
        cout << "Linked List is a Palindrome\n";
    } else {
        cout << "Linked List is NOT a Palindrome\n";
    }

    return 0;
}
