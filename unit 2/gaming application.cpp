#include <iostream>
using namespace std;

// Structure to represent a node in the circular linked list
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class CircularHeaderLinkedList {
private:
    Node* header;

public:
    CircularHeaderLinkedList() {
        header = nullptr; // Initialize the header
    }

    // Function to add a player's score at the front of the linked list
    void addScoreAtFront(int value) {
        Node* newNode = new Node(value);
        if (!header) {
            // If the list is empty, make the new node point to itself
            newNode->next = newNode;
            header = newNode; // Set the header to the new node
        } else {
            newNode->next = header->next; // New node points to the first node
            header->next = newNode; // Header points to the new first node
        }
    }

    // Function to add a player's score at the end of the linked list
    void addScoreAtEnd(int value) {
        Node* newNode = new Node(value);
        if (!header) {
            // If the list is empty, make the new node point to itself
            newNode->next = newNode;
            header = newNode; // Set the header to the new node
        } else {
            newNode->next = header->next; // New node points to the first node
            header->next = newNode; // Header points to the new node
            header = newNode; // Update the header to the new last node
        }
    }

    // Function to display the circular linked list along with the total number of nodes
    void displayScores() {
        if (!header) {
            cout << "List is empty" << endl;
            return;
        }

        Node* current = header->next;
        int count = 0;
        
        do {
            current = current->next;
            count++;
        } while (current != header->next);

        cout << "Number of nodes in the CLL is " << count << endl;
        
        int ncount = 0;
        
        do{
            cout << current->data << " ";
            current = current->next;
            count++;
        } while (current != header->next);
    }
};

int main() {
    CircularHeaderLinkedList cll;

    int n, m;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int score;
        cin >> score;
        cll.addScoreAtFront(score);
    }

    cin >> m;

    for (int i = 0; i < m; i++) {
        int score;
        cin >> score;
        cll.addScoreAtEnd(score);
    }

    cll.displayScores();

    return 0;
}
