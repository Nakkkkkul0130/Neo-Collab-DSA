#include <iostream>
#include <vector>

using namespace std;

int countOnes(int num) {
    int count = 0;
    while (num > 0) {
        if (num % 2 == 1) {
            count++;
        }
        num /= 2;
    }
    return count;
}

bool customCompare(int a, int b) {
    int countA = countOnes(a);
    int countB = countOnes(b);

    if (countA == countB) {
        return a < b; 
    }

    return countA < countB; 
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (customCompare(arr[j], pivot)) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Quick-Sort function
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
