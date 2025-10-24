#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Order {
    int id;
    string item;
    int quantity;
};

int main() {
    queue<Order> orderQueue;
    int idCounter = 1;

    // Adding (enqueue)
    orderQueue.push({idCounter++, "Burger", 2});
    orderQueue.push({idCounter++, "Pizza", 1});
    orderQueue.push({idCounter++, "Fries", 3});

    // Removing (dequeue)
    cout << "Processing Orders:\n";
    while (!orderQueue.empty()) {
        Order o = orderQueue.front();
        cout << "Order #" << o.id << ": " << o.item
             << " x" << o.quantity << endl;
        orderQueue.pop();
    }

    return 0;
}
