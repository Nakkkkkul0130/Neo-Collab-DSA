#include <iostream>
#include <vector>

using namespace std;

vector<int> merge(vector<int>& left, vector<int>& right) {
    vector<int> result;
    int i = 0, j = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i] > right[j]) {
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

vector<int> mergeSort(vector<int>& productIDs) {
    if (productIDs.size() <= 1) {
        return productIDs;
    }

    int mid = productIDs.size() / 2;
    vector<int> left(productIDs.begin(), productIDs.begin() + mid);
    vector<int> right(productIDs.begin() + mid, productIDs.end());

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}

int main() {
    int n;
    cin >> n;

    vector<int> productIDs(n);

    for (int i = 0; i < n; i++) {
        cin >> productIDs[i];
    }

    vector<int> sortedProductIDs = mergeSort(productIDs);

    for (int i = 0; i < n; i++) {
        cout << sortedProductIDs[i] << " ";
    }
    cout << endl;

    return 0;
}
