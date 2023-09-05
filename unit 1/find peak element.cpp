#include <iostream>
#include <vector>
using namespace std;
int findPeakElement(const vector<int>& mountain) {
    int left = 0;
    int right = mountain.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (mountain[mid] < mountain[mid + 1]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return mountain[left];
}

int main() {
    int n;
    cin >> n;

    vector<int> mountain(n);
    for (int i = 0; i < n; ++i) {
        cin >> mountain[i];
    }

    int peak = findPeakElement(mountain);

    cout << peak << endl;

    return 0;
}