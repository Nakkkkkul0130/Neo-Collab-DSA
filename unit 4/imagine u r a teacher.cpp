#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;


int partition(vector<double>& gpas, int low, int high) {
    double pivot = gpas[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (gpas[j] >= pivot) {
            i++;
            swap(gpas[i], gpas[j]);
        }
    }

    swap(gpas[i + 1], gpas[high]);
    return i + 1;
}


void quickSort(vector<double>& gpas, int low, int high) {
    if (low < high) {
        int pi = partition(gpas, low, high);
        quickSort(gpas, low, pi - 1);
        quickSort(gpas, pi + 1, high);
    }
}

int main() {
    int n;
    cin >> n;

    vector<double> gpas(n);

    for (int i = 0; i < n; i++) {
        cin >> gpas[i];
    }

    quickSort(gpas, 0, n - 1);

    cout << fixed << setprecision(1); 

    for (int i = 0; i < n; i++) {
        cout << gpas[i] << " ";
    }
    cout << endl;

    return 0;
}
