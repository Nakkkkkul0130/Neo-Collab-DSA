#include <iostream>
#include <vector>
#include <algorithm>

const int maxSize = 100;

void insertIntoMaxHeap(std::vector<int> &heap, int job) {
    if (heap.size() == maxSize) {
        std::cout << "Heap is full. Cannot insert more jobs." << std::endl;
        return;
    }

    heap.push_back(job);
    int index = heap.size() - 1;

    while (index > 0) {
        int parentIndex = (index - 1) / 2;
        if (heap[parentIndex] >= heap[index]) {
            break;
        }
        std::swap(heap[parentIndex], heap[index]);
        index = parentIndex;
    }
}

int main() {
    std::vector<int> maxHeap;
    int job;

    while (std::cin >> job) {
        insertIntoMaxHeap(maxHeap, job);
    }

    for (int i = 0; i < maxHeap.size(); i++) {
        std::cout << maxHeap[i] << " ";
    }

    return 0;
}
