#include <iostream>
#include <string>
#include <vector>

class Queue {
private:
    int front;
    int rear;
    std::vector<char> elements;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(char item) {
        elements.push_back(item);
        if (front == -1) {
            front = 0;
        }
        rear++;
    }

    char dequeue() {
        if (isEmpty()) {
            return '\0';  // Return null character to indicate an empty queue.
        }
        char item = elements[front];
        front++;
        return item;
    }

    bool isEmpty() {
        return front > rear;
    }
};

int findFirstUniqueCharacter(const std::string& input) {
    int count[26] = {0};  // Assuming lowercase alphabets, so 26 characters

    // Step 1: Count the occurrences of each character and enqueue them
    Queue queue;
    for (char ch : input) {
        count[ch - 'a']++;
        queue.enqueue(ch);
    }

    // Step 2: Dequeue and check for the first unique character
    int index = 0;
    while (!queue.isEmpty()) {
        char ch = queue.dequeue();
        if (count[ch - 'a'] == 1) {
            return index;
        }
        index++;
    }

    return -1;  // No unique character found
}

int main() {
    std::string input;
    std::cin >> input;  // Read the entire input line

    int result = findFirstUniqueCharacter(input);

    std::cout << result << std::endl;

    return 0;
}
