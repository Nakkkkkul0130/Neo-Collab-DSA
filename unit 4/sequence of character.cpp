#include <iostream>
#include <vector>

using namespace std;

int partition(vector<char>& chars, int low, int high) {
    char pivot = chars[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (chars[j] >= pivot) {
            i++;
            swap(chars[i], chars[j]);
        }
    }

    swap(chars[i + 1], chars[high]);
    return i + 1;
}


void quickSort(vector<char>& chars, int low, int high) {
    if (low < high) {
        int pi = partition(chars, low, high);
        quickSort(chars, low, pi - 1);
        quickSort(chars, pi + 1, high);
    }
}

int main() {
    int n;
    cin >> n;

    vector<char> chars(n);

    for (int i = 0; i < n; i++) {
        cin >> chars[i];
    }

    quickSort(chars, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << chars[i] << " ";
    }
    cout << endl;

    return 0;
}
