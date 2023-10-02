#include <iostream>
#include <vector>

using namespace std;

bool compare(char a, char b) {
    return a > b;
}


vector<char> merge(vector<char>& left, vector<char>& right) {
    vector<char> result;
    int i = 0, j = 0;

    while (i < left.size() && j < right.size()) {
        if (compare(left[i], right[j])) {
            result.push_back(left[i]);
            i++;
        } else {
            result.push_back(right[j]);
            j++;
        }
    }

    while (i < left.size()) {
        result.push_back(left[i]);
        i++;
    }

    while (j < right.size()) {
        result.push_back(right[j]);
        j++;
    }

    return result;
}

vector<char> mergeSort(vector<char>& arr) {
    if (arr.size() <= 1) {
        return arr;
    }

    int mid = arr.size() / 2;
    vector<char> left(arr.begin(), arr.begin() + mid);
    vector<char> right(arr.begin() + mid, arr.end());

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}

int main() {
    int n;
    cin >> n;

    vector<char> runes(n);

    for (int i = 0; i < n; i++) {
        cin >> runes[i];
    }

    vector<char> sortedRunes = mergeSort(runes);

    for (int i = 0; i < n; i++) {
        cout << sortedRunes[i] << " ";
    }
    cout << endl;

    return 0;
}
