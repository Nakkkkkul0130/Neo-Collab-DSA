#include <iostream>

using namespace std;

// Define a struct for a transaction record node
struct TransactionNode {
    int transactionID;
    float transactionAmount;
    TransactionNode* next;

    TransactionNode(int id, float amount) : transactionID(id), transactionAmount(amount), next(nullptr) {}
};

// Function to create a new transaction record node
TransactionNode* createTransactionNode(int id, float amount) {
    return new TransactionNode(id, amount);
}

// Function to insert a transaction record at the end of the circular linked list
TransactionNode* insertTransaction(TransactionNode* header, int id, float amount) {
    TransactionNode* newNode = createTransactionNode(id, amount);

    if (!header) {
        newNode->next = newNode; // Circular list with one node
        return newNode;
    }

    TransactionNode* tail = header;
    while (tail->next != header) {
        tail = tail->next;
    }

    tail->next = newNode;
    newNode->next = header;

    return header;
}

// Function to delete a transaction record at the given index
TransactionNode* deleteTransactionAtIndex(TransactionNode* header, int index) {
    if (!header) {
        cout << "Invalid index. Circular list is empty." << endl;
        return nullptr;
    }

    if (index < 0) {
        cout << "Invalid index. Index must be non-negative." << endl;
        return header;
    }

    // Special case: Deleting the only node in the circular list
    if (index == 0 && header->next == header) {
        delete header;
        cout << "Transaction record at index 0 has been successfully deleted." << endl;
        return nullptr;
    }

    TransactionNode* current = header;
    TransactionNode* prev = nullptr;
    int currentIndex = 0;

    do {
        if (currentIndex == index) {
            if (prev) {
                prev->next = current->next;
            } else {
                // Deleting the head node
                TransactionNode* tail = header;
                while (tail->next != header) {
                    tail = tail->next;
                }
                header = header->next;
                tail->next = header;
            }

            delete current;
            cout << "Transaction record at index " << index << " has been successfully deleted." << endl;
            return header;
        }

        prev = current;
        current = current->next;
        currentIndex++;
    } while (current != header);

    cout << "Invalid index." << endl;
    return header;
}

// Function to display the transaction records
void displayTransactions(TransactionNode* header) {
    if (!header) {
        cout << "List is empty." << endl;
        return;
    }

    TransactionNode* current = header;
    int index = 0;

    do {
        cout << "Index " << index << ": Transaction ID: " << current->transactionID << ", Amount: " << current->transactionAmount << endl;
        current = current->next;
        index++;
    } while (current != header);
}

int main() {
    int n;
    cin >> n;

    TransactionNode* header = nullptr;

    // Insert initial transaction records
    for (int i = 0; i < n; ++i) {
        int id;
        float amount;
        cin >> id >> amount;
        header = insertTransaction(header, id, amount);
    }

    int indexToDelete;
    cin >> indexToDelete;

    // Delete a transaction record at the given index
    header = deleteTransactionAtIndex(header, indexToDelete);

    // Display the updated transaction records
    cout << "Updated transaction records:" << endl;
    displayTransactions(header);

    // Free memory (optional, not shown in the sample outputs)
    if (header) {
        TransactionNode* current = header;
        do {
            TransactionNode* temp = current;
            current = current->next;
            delete temp;
        } while (current != header);
    }

    return 0;
}
