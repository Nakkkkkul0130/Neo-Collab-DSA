#include <iostream>
#include <string>
#include <vector>

using namespace std;

void findPatternOccurrences(const string& text, const string& pattern) {
    int textLen = text.length();
    int patternLen = pattern.length();

    if (patternLen > textLen) {
        cout << "Pattern is longer than the string" << endl;
        return;
    }

    vector<int> positions;

    for (int i = 0; i <= textLen - patternLen; i++) {
        bool found = true;
        for (int j = 0; j < patternLen; j++) {
            if (text[i + j] != pattern[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            positions.push_back(i);
        }
    }

    if (!positions.empty()) {
        for (int pos : positions) {
            cout << "Pattern found at index " << pos << endl;
        }
    } else {
        cout << "Pattern not found" << endl;
    }
}

int main() {
    string text, pattern;
    getline(cin, text);
    getline(cin, pattern);

    findPatternOccurrences(text, pattern);

    return 0;
}
