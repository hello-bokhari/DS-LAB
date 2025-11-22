#include <iostream>
using namespace std;

class Hash {
private:
    static const int S = 15;
    int roll[S];
    string name[S];
    bool used[S];
public:
    Hash() { for (int i = 0; i < S; i++) used[i] = false; }

    void insertRec(int r, string n) {
        int base = r % S;
        for (int i = 0; i < S; i++) {
            int idx = (base + i * i) % S;
            if (!used[idx]) {
                roll[idx] = r;
                name[idx] = n;
                used[idx] = true;
                cout << "Inserted " << idx << endl;
                return;
            }
        }
        cout << "Full" << endl;
    }

    void findRec(int r) {
        int base = r % S;
        for (int i = 0; i < S; i++) {
            int idx = (base + i * i) % S;
            if (used[idx] && roll[idx] == r) {
                cout << name[idx] << endl;
                return;
            }
        }
        cout << "Not found" << endl;
    }
};

int main() {
    Hash h;
    h.insertRec(101, "Ali");
    h.insertRec(116, "Sara");
    h.findRec(116);
    h.findRec(200);
}
