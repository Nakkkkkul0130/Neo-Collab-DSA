#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

vector<pair<int, int>> merge(vector<pair<int, int>>& left, vector<pair<int, int>>& right) {
    vector<pair<int, int>> result;
    int i = 0, j = 0;

    while (i < left.size() && j < right.size()) {
        if (compare(left[i], right[j])) {
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

vector<pair<int, int>> mergeSort(vector<pair<int, int>>& arr) {
    if (arr.size() <= 1) {
        return arr;
    }

    int mid = arr.size() / 2;
    vector<pair<int, int>> left(arr.begin(), arr.begin() + mid);
    vector<pair<int, int>> right(arr.begin() + mid, arr.end());

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    map<int, int> frequencyMap;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        frequencyMap[nums[i]]++;
    }

    vector<pair<int, int>> pairs;
    for (const auto& kv : frequencyMap) {
        pairs.push_back({kv.first, kv.second});
    }

    vector<pair<int, int>> sortedPairs = mergeSort(pairs);

    for (const auto& p : sortedPairs) {
        for (int i = 0; i < p.second; i++) {
            cout << p.first << " ";
        }
    }

    cout << endl;

    return 0;
}
