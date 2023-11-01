#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void heapify(vector<int>& heap, int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int smallest = i;
    if (left < heap.size() && heap[left] < heap[smallest]) {
        smallest = left;
    }
    if (right < heap.size() && heap[right] < heap[smallest]) {
        smallest = right;
    }
    if (smallest != i) {
        swap(heap[i], heap[smallest]);
        heapify(heap, smallest);
    }
}

int deleteMin(vector<int>& heap) {
    int min = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    heapify(heap, 0);
    return min;
}

int main() {
    int n;
    cin >> n;
    vector<int> heap(n);
    for (int i = 0; i < n; i++) {
        cin >> heap[i];
    }
    make_heap(heap.begin(), heap.end(), greater<int>());
    int min = deleteMin(heap);
    for (int i = 0; i < heap.size(); i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
    return 0;
}