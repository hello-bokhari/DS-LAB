#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string data;
    Node* next;
    Node(string val) {
        data = val;
        next = NULL;
    }
};

class SLinkList {
public:
    Node* head;
    Node* tail;
    SLinkList() {
        head = NULL;
        tail = NULL;
    }

    void reserveTicket(string val) {
        Node* n = new Node(val);

        if (head == NULL) {
            head = tail = n;
            cout << "Ticket reserved for " << val << endl;
            return;
        }

        if (val < head->data) {
            n->next = head;
            head = n;
            cout << "Ticket reserved for " << val << endl;
            return;
        }

        Node* curr = head;
        Node* pre = NULL;
        while (curr != NULL && curr->data < val) {
            pre = curr;
            curr = curr->next;
        }

        if (curr != NULL && curr->data == val) {
            cout << "Passenger " << val << " already has a reservation.\n";
            delete n;
            return;
        }

        pre->next = n;
        n->next = curr;
        if (curr == NULL) tail = n;
        cout << "Ticket reserved for " << val << endl;
    }

    void cancelReservation(string val) {
        if (head == NULL) {
            cout << "No reservations to cancel.\n";
            return;
        }

        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            if (head == NULL) tail = NULL;
            delete temp;
            cout << "Reservation cancelled for " << val << endl;
            return;
        }

        Node* curr = head;
        Node* pre = NULL;
        while (curr != NULL && curr->data != val) {
            pre = curr;
            curr = curr->next;
        }

        if (curr == NULL) {
            cout << "No reservation found for " << val << endl;
            return;
        }

        pre->next = curr->next;
        if (curr == tail) tail = pre;
        delete curr;
        cout << "Reservation cancelled for " << val << endl;
    }

    void checkReservation(string val) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == val) {
                cout << "Yes, " << val << " has a reservation.\n";
                return;
            }
            temp = temp->next;
        }
        cout << "No reservation found for " << val << endl;
    }

    void displayPassengers() {
        if (head == NULL) {
            cout << "No passengers reserved.\n";
            return;
        }
        cout << "Passenger List: ";
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    SLinkList flight;
    int choice;
    string name;

    do {
        cout << "\n--- Airline Ticket Reservation Menu ---\n";
        cout << "1. Reserve a ticket\n";
        cout << "2. Cancel a reservation\n";
        cout << "3. Check reservation\n";
        cout << "4. Display all passengers\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";

        if (!(cin >> choice)) {  
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        cin.ignore();

        switch (choice) {
        case 1:
            cout << "Enter passenger name: ";
            getline(cin, name);
            flight.reserveTicket(name);
            break;
        case 2:
            cout << "Enter passenger name: ";
            getline(cin, name);
            flight.cancelReservation(name);
            break;
        case 3:
            cout << "Enter passenger name: ";
            getline(cin, name);
            flight.checkReservation(name);
            break;
        case 4:
            flight.displayPassengers();
            break;
        case 5:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}
