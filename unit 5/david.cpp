#include <iostream>
#include <vector>
#include <algorithm>

void minHeapify(std::vector<int> &heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap.size() && heap[left] < heap[smallest]) {
        smallest = left;
    }

    if (right < heap.size() && heap[right] < heap[smallest]) {
        smallest = right;
    }

    if (smallest != index) {
        std::swap(heap[index], heap[smallest]);
        minHeapify(heap, smallest);
    }
}

void insertIntoMinHeap(std::vector<int> &heap, int distance) {
    heap.push_back(distance);
    int index = heap.size() - 1;

    while (index > 0) {
        int parentIndex = (index - 1) / 2;
        if (heap[parentIndex] <= heap[index]) {
            break;
        }
        std::swap(heap[parentIndex], heap[index]);
        index = parentIndex;
    }
}

int main() {
    std::vector<int> minHeap;
    int distance;

    while (std::cin >> distance) {
        insertIntoMinHeap(minHeap, distance);
    }

    for (int i = 0; i < minHeap.size(); i++) {
        std::cout << minHeap[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
