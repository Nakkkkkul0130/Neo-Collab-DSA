#include <iostream>
#include <vector>
#include <algorithm>

void maxHeapify(std::vector<char> &heap, int index) {
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

void insertIntoMaxHeap(std::vector<char> &heap, char message) {
    heap.push_back(message);
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
    std::vector<char> maxHeap;
    char message;

    while (std::cin >> message) {
        insertIntoMaxHeap(maxHeap, message);
    }

    for (char c : maxHeap) {
        std::cout << c << " ";
    }
    std::cout << std::endl;

    return 0;
}
