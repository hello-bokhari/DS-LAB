#include <iostream>
using namespace std;

struct PairStore { int a, b; bool used; };

bool findPairs(int arr[], int n) {
    PairStore map[1000];
    for (int i = 0; i < 1000; i++) map[i].used = false;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int s = arr[i] + arr[j];
            if (map[s].used) {
                cout << "(" << map[s].a << "," << map[s].b << ") and (" << arr[i] << "," << arr[j] << ")" << endl;
                return true;
            }
            map[s].a = arr[i];
            map[s].b = arr[j];
            map[s].used = true;
        }
    }
    cout << "No pairs" << endl;
    return false;
}

int main() {
    int a1[] = {3,4,7,1,2,9,8};
    findPairs(a1, 7);
    int a2[] = {65,30,7,90,1,9,8};
    findPairs(a2, 7);
}
