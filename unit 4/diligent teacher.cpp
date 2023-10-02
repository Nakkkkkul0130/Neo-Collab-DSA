#include <iostream>
#include <vector>

using namespace std;


int partition(vector<double>& marks, int low, int high) {
    double pivot = marks[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (marks[j] >= pivot) {
            i++;
            swap(marks[i], marks[j]);
        }
    }

    swap(marks[i + 1], marks[high]);
    return i + 1;
}


void quickSort(vector<double>& marks, int low, int high) {
    if (low < high) {
        int pi = partition(marks, low, high);
        quickSort(marks, low, pi - 1);
        quickSort(marks, pi + 1, high);
    }
}

int main() {
    int n;
    cin >> n;

    vector<double> marks(n);

    for (int i = 0; i < n; i++) {
        cin >> marks[i];
    }

    quickSort(marks, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << marks[i] << " ";
    }
    cout << endl;

    return 0;
}
