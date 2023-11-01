#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> minHeap; 
    int priority;

    while (cin >> priority) {
        minHeap.push_back(priority);  
        push_heap(minHeap.begin(), minHeap.end(), greater<int>());  
    }

    for (int i = 0; i < minHeap.size(); i++) {
        cout << minHeap[i] << " ";
    }
    cout << endl;

    return 0;
}
