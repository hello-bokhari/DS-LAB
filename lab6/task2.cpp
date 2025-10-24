#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <cmath>
using namespace std;

struct Transaction {
    int id;
    double amount;
    string desc;
    int flag; // 1 = Sale, 0 = Refund, 2 = Reversed
};

struct Node {
    Transaction data;
    Node* next;
    Node(Transaction t) : data(t), next(nullptr) {}
};

class TransactionStack {
    Node* top;
    int counter;
public:
    TransactionStack() : top(nullptr), counter(0) {}

    double applyDiscount(double amt) {
        if (amt >= 1500) return amt * 0.70; // 30% off
        else if (amt >= 1000) return amt * 0.85; // 15% off
        else if (amt >= 500) return amt * 0.95; // 5% off
        return amt;
    }

    string shortenDesc(string d) {
        if (d.length() > 20)
            return d.substr(0, 17) + "...";
        return d;
    }

    void push(Transaction t) {
        t.id = ++counter;
        t.desc = shortenDesc(t.desc);

        if (t.amount >= 0) { // Sale
            t.flag = 1;
            t.amount = applyDiscount(t.amount);
        } else {
            t.flag = 0; // Refund
        }

        Node* newNode = new Node(t);
        newNode->next = top;
        top = newNode;
    }

    Transaction pop() {
        if (!top) {
            cout << "Stack Underflow!\n";
            return Transaction{-1, 0, "N/A", -1};
        }
        Node* temp = top;
        Transaction t = temp->data;
        top = top->next;
        delete temp;

        // Reverse logic
        t.amount *= -1;
        t.desc += " [REVERSED]";
        t.flag = 2;
        return t;
    }

    void display() {
        cout << "\nCurrent Transactions in Stack:\n";
        if (!top) {
            cout << "(Stack is empty)\n";
            return;
        }

        Node* curr = top;
        cout << "Top → ";
        while (curr) {
            cout << "[id=" << curr->data.id
                 << ", amt=" << curr->data.amount
                 << ", desc=\"" << curr->data.desc
                 << "\", flag=" << curr->data.flag << "]\n";
            curr = curr->next;
        }
        cout << "Bottom\n";
    }
};

// --------------------- INFIX TO POSTFIX -------------------------
int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

string infixToPostfix(string infix) {
    stack<char> st;
    string postfix = "";
    for (char c : infix) {
        if (isdigit(c) || c == '.') postfix += c;
        else if (c == '(') st.push(c);
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += ' ';
                postfix += st.top();
                st.pop();
            }
            st.pop();
        } else if (c == ' ') continue;
        else {
            postfix += ' ';
            while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                postfix += st.top();
                postfix += ' ';
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        postfix += ' ';
        postfix += st.top();
        st.pop();
    }
    return postfix;
}

// --------------------- POSTFIX EVALUATION -------------------------
double evaluatePostfix(string expr) {
    stack<double> s;
    string num = "";
    for (size_t i = 0; i < expr.size(); i++) {
        char c = expr[i];
        if (isdigit(c) || c == '.') {
            num += c;
        } else if (c == ' ') {
            if (!num.empty()) {
                s.push(stod(num));
                num = "";
            }
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            double b = s.top(); s.pop();
            double a = s.top(); s.pop();
            switch (c) {
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/': s.push(a / b); break;
            }
        }
    }
    return s.top();
}

// --------------------- MAIN FUNCTION -------------------------
int main() {
    srand(time(0));

    Transaction transactions[7] = {
        {0, 1200, "Sale: Blue Jacket", 1},
        {0, 450, "Sale: Cotton Socks", 1},
        {0, -300, "Refund: Defective Shirt", 0},
        {0, 1700, "Sale: Leather Jacket", 1},
        {0, 600, "Sale: Hoodie", 1},
        {0, -150, "Refund: Wrong Size", 0},
        {0, 999, "Sale: Sunglasses", 1}
    };

    TransactionStack stack;

    // Push 4 random transactions
    for (int i = 0; i < 4; i++) {
        int r = rand() % 7;
        stack.push(transactions[r]);
    }

    cout << "Pushed Transactions:";
    stack.display();

    // Expression evaluation
    string infix = "(100 + 20) * 0.9 - 5";
    string postfix = infixToPostfix(infix);
    double result = evaluatePostfix(postfix);

    cout << "\nIntermediate Expression Calculation:\n";
    cout << "Infix: " << infix << endl;
    cout << "Postfix: " << postfix << endl;
    cout << "Evaluated Result: " << result << endl;

    // Pop one transaction
    cout << "\nPop (remove) one transaction:\n";
    Transaction popped = stack.pop();
    cout << "Popped Transaction: " << popped.desc
         << " | Amount: " << popped.amount
         << " | Flag: " << popped.flag << endl;

    cout << "\nFinal Stack Output:";
    stack.display();

    return 0;
}
