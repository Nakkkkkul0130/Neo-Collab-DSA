#include <iostream>
#include <vector>
using namespace std;

const int maxSize = 100;

void maxHeapify(vector<int>& heap, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap.size() && heap[left] > heap[largest])
        largest = left;
    if (right < heap.size() && heap[right] > heap[largest])
        largest = right;

    if (largest != i) {
        swap(heap[i], heap[largest]);
        maxHeapify(heap, largest);
    }
}

void insertBid(vector<int>& heap, int bid) {
    if (heap.size() == maxSize) {
        if (bid < heap[0])
            return; 
        heap[0] = bid;
        maxHeapify(heap, 0);
    } else {
        heap.push_back(bid);
        int index = heap.size() - 1;
        while (index > 0 && heap[(index - 1) / 2] < bid) {
            heap[index] = heap[(index - 1) / 2];
            index = (index - 1) / 2;
        }
        heap[index] = bid;
    }
}

int main() {
    vector<int> heap;
    int bid;

    while (cin >> bid) {
        insertBid(heap, bid);
    }

    for (int i = 0; i < heap.size(); i++) {
        cout << heap[i];
        if (i < heap.size() - 1)
            cout << " ";
    }
    cout << endl;

    return 0;
}