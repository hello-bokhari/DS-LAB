#include <iostream>
#include <cstring>
using namespace std;

#define MAX 50

class Stack {
    char arr[MAX];
    int top;
public:
    Stack() { top = -1; }

    bool isFull() { return top == MAX - 1; }
    bool isEmpty() { return top == -1; }

    void push(char ch) {
        if (isFull()) cout << "Stack Overflow!\n";
        else arr[++top] = ch;
    }

    char pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!\n";
            return '\0';
        }
        return arr[top--];
    }
};

int main() {
    Stack s;
    string str = "BORROWROB";
    for (char c : str)
        s.push(c);

    string reversed = "";
    while (!s.isEmpty())
        reversed += s.pop();

    cout << "Original String: " << str << endl;
    cout << "Reversed String: " << reversed << endl;

    if (str == reversed)
        cout << "Result: It is a palindrome!" << endl;
    else
        cout << "Result: Not a palindrome." << endl;

    return 0;
}
