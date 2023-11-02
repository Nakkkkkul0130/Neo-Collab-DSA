#include <iostream>
#include <vector>

using namespace std;

void maxHeapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void buildMaxHeap(vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    buildMaxHeap(arr);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
}

int main() {
    int no, n1, n2;
    cin >> no;

    vector<int> brightnessLevels;

    for (int i = 0; i < no; i++) {
        int brightness;
        cin >> brightness;
        brightnessLevels.push_back(brightness);
    }

    cin >> n1;
    for (int i = 0; i < n1; i++) {
        int brightness;
        cin >> brightness;
        brightnessLevels.push_back(brightness);
    }

    cin >> n2;
    for (int i = 0; i < n2; i++) {
        int brightness;
        cin >> brightness;
        brightnessLevels.push_back(brightness);
    }

    heapSort(brightnessLevels);

    for (int i = 0; i < brightnessLevels.size(); i++) {
        cout << brightnessLevels[i];
        if (i < brightnessLevels.size() - 1) {
            cout << " ";
        }
    }

    return 0;
}
