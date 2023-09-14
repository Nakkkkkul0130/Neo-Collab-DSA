#include <iostream>
#include <deque>

using namespace std;

int main() {
    deque<string> waitlist; // Double-ended queue to store customer names

    while (true) {
        int choice;
        cin >> choice;

        if (choice == 1) {
            string customerName;
            cin >> customerName;
            waitlist.push_back(customerName);
            cout << customerName << " has been added to the waitlist." << endl;
        } else if (choice == 2) {
            if (!waitlist.empty()) {
                cout << waitlist.front() << " has been removed from the waitlist." << endl;
                waitlist.pop_front();
            } else {
                cout << "Error: Waitlist is empty" << endl;
            }
        } else if (choice == 3) {
            if (!waitlist.empty()) {
                string customerName = waitlist.front();
                waitlist.pop_front();
                waitlist.push_back(customerName);
                cout << customerName << " has been moved to the back of the waitlist." << endl;
            } else {
                cout << "Error: Waitlist is empty" << endl;
            }
        } else if (choice == 4) {
            cout << "Current waitlist:" << endl;
            if (!waitlist.empty()) {
                for (const string& customer : waitlist) {
                    cout << customer << endl;
                }
            } else {
                cout << "Empty" << endl;
            }
        } else if (choice == 5) {
            cout << "Exiting" << endl;
            break;
        } else {
            cout << "Invalid option!" << endl;
        }
    }

    return 0;
}

