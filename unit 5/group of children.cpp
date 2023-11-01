#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    priority_queue<int> maxHeap;
    vector<int> excitementLevels;

    for (int i = 0; i < n; i++) {
        int excitement;
        cin >> excitement;
        maxHeap.push(excitement);
    }

    int mostExcitedChild = maxHeap.top();
    cout << mostExcitedChild << endl;

    maxHeap.pop(); 

    while (!maxHeap.empty()) {
        excitementLevels.push_back(maxHeap.top());
        maxHeap.pop();
    }

    for (int excitement : excitementLevels) {
        cout << excitement << " ";
    }

    return 0;
}
