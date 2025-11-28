#include <iostream>
#include <cstring>
using namespace std;

void rabinKarpSearch(char text[], char pattern[]) {
    int textLength = strlen(text);
    int patternLength = strlen(pattern);
    const int prime = 101;
    const int base = 256;
    int patternHash = 0;
    int windowHash = 0;
    int highestPower = 1;
    int foundIndices[100];
    int foundCount = 0;

    cout << "\n--- Rabin-Karp Search Log ---\n";

    for(int i = 0; i < patternLength - 1; i++)
        highestPower = (highestPower * base) % prime;

    for(int i = 0; i < patternLength; i++) {
        patternHash = (patternHash * base + pattern[i]) % prime;
        windowHash = (windowHash * base + text[i]) % prime;
    }

    for(int i = 0; i <= textLength - patternLength; i++) {
        if(patternHash == windowHash) {
            bool exactMatch = true;
            for(int j = 0; j < patternLength; j++) {
                if(text[i + j] != pattern[j]) {
                    exactMatch = false;
                    cout << "Hash Collision at index " << i << "\n";
                    break;
                }
            }
            if(exactMatch) foundIndices[foundCount++] = i;
        }

        if(i < textLength - patternLength) {
            windowHash = (base * (windowHash - text[i] * highestPower) + text[i + patternLength]) % prime;
            if(windowHash < 0) windowHash += prime;
        }
    }

    cout << "\nPattern Found At: ";
    if(foundCount == 0) cout << "No matches found";
    else {
        for(int i = 0; i < foundCount; i++) {
            cout << foundIndices[i];
            if(i != foundCount - 1) cout << ", ";
        }
    }
    cout << endl;
}

int main() {
    char text[300], pattern[100];
    cout << "Enter the full text: ";
    cin.getline(text, 300);
    cout << "Enter the pattern to search for: ";
    cin.getline(pattern, 100);
    rabinKarpSearch(text, pattern);
    return 0;
}
