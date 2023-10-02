#include <iostream>
#include <vector>

using namespace std;

vector<int> merge(vector<int> left, vector<int> right) {
    vector<int> result;
    int i = 0, j = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) {
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


vector<int> mergeSort(vector<int> arr) {
    if (arr.size() <= 1) {
        return arr;
    }

    int mid = arr.size() / 2;
    vector<int> left(arr.begin(), arr.begin() + mid);
    vector<int> right(arr.begin() + mid, arr.end());

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] != 0 && arr[i] != 1) {
            cout << "Invalid input." << endl;
            return 0;
        }
    }

    vector<int> sortedArr = mergeSort(arr);

    for (int i = 0; i < n; i++) {
        cout << sortedArr[i] << " ";
    }
    cout << endl;

    return 0;
}
