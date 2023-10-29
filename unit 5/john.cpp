#include <iostream>
#include <vector>
#include <algorithm>

void maxHeapify(std::vector<int> &heap, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap.size() && heap[left] > heap[largest]) {
        largest = left;
    }

    if (right < heap.size() && heap[right] > heap[largest]) {
        largest = right;
    }

    if (largest != index) {
        std::swap(heap[index], heap[largest]);
        maxHeapify(heap, largest);
    }
}

void insertIntoMaxHeap(std::vector<int> &heap, int popularity) {
    heap.push_back(popularity);
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
    int popularity;

    while (std::cin >> popularity) {
        insertIntoMaxHeap(maxHeap, popularity);
    }

    for (int p : maxHeap) {
        std::cout << p << " ";
    }
    std::cout << std::endl;

    return 0;
}
