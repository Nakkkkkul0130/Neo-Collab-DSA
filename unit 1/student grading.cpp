#include <iostream>
#include <string>

using namespace std;

void selectionSort(string arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
        cout << "After Iteration " << i + 1 << ": ";
        for (int k = 0; k < n; ++k) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;

    string name[n];
    cin.ignore(); 
    for (int i = 0; i < n; ++i) {
        cin >> name[i];
    } 

    cout << "Initial order: ";
    for (int i = 0; i < n; ++i) {
        cout << name[i] << " ";
    }
    cout << endl;
    selectionSort(name, n);

    cout << "Sorted order: ";
    for (int i = 0; i < n; ++i) {
        cout << name[i] << " ";
    }
    cout << endl;
    return 0;
}