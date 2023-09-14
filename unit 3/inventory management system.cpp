#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Book {
    string title;
    int quantity;
    int restockPriority;

    // Overloading the '<' operator to compare books based on restock priority.
    bool operator<(const Book& other) const {
        return restockPriority > other.restockPriority; // Lower priority comes first.
    }
};

int main() {
    priority_queue<Book> inventory;

    while (true) {
        int choice;
        cin >> choice;

        if (choice == 1) {
            string title;
            int quantity, priority;
            cin.ignore(); // Clear the newline character from the previous input
            getline(cin, title);
            cin >> quantity >> priority;
            
            if (!title.empty() && quantity >= 0 && priority >= 1 && priority <= 5) {
                inventory.push({title, quantity, priority});
                cout << "Book added to the inventory." << endl;
            } else {
                cout << "Invalid input. Please enter a valid book." << endl;
            }
        } else if (choice == 2) {
            if (!inventory.empty()) {
                Book restockedBook = inventory.top();
                inventory.pop();
                cout << "Restocked book: " << restockedBook.title << endl;
            } else {
                cout << "No books in the inventory." << endl;
            }
        } else if (choice == 3) {
            if (!inventory.empty()) {
                Book nextBookToRestock = inventory.top();
                cout << "Next book to restock: " << nextBookToRestock.title << endl;
            } else {
                cout << "No books in the inventory." << endl;
            }
        } else if (choice == 4) {
            cout << "Exiting the application." << endl;
            break;
        } else {
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }

    return 0;
}

