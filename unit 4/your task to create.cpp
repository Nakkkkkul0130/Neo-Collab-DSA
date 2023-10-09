#include <iostream>
#include <vector>

using namespace std;

bool isValidInorderTraversal(const vector<int>& arr) {
    int n = arr.size();

    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }

    return true;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (isValidInorderTraversal(arr)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
