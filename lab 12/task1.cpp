#include <iostream>
#include <cstring>
using namespace std;

void bruteForceSearch(char text[], char pattern[]) {
    int textLength = strlen(text);
    int patternLength = strlen(pattern);
    int comparisonCount = 0;
    int foundIndices[100];
    int foundCount = 0;

    for(int i = 0; i <= textLength - patternLength; i++) {
        bool found = true;
        for(int j = 0; j < patternLength; j++) {
            comparisonCount++;
            if(text[i + j] != pattern[j]) {
                found = false;
                break;
            }
        }
        if(found) foundIndices[foundCount++] = i;
    }

    cout << "\nPattern Found At: ";
    if(foundCount == 0) cout << "No matches found";
    else {
        for(int i = 0; i < foundCount; i++) {
            cout << foundIndices[i];
            if(i != foundCount - 1) cout << ", ";
        }
    }
    cout << "\nTotal Comparisons Performed: " << comparisonCount << endl;
}

int main() {
    char text[200], pattern[50];
    cout << "Enter the full text: ";
    cin.getline(text, 200);
    cout << "Enter the word/pattern to search for: ";
    cin.getline(pattern, 50);

    bruteForceSearch(text, pattern);
    return 0;
}
