#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Patient {
    int priority;
    string name;

    // Overloading the '<' operator to compare patients based on priority.
    bool operator<(const Patient& other) const {
        return priority > other.priority; // Higher priority patients come first.
    }
};

int main() {
    priority_queue<Patient> emergencyQueue;

    while (true) {
        int choice;
        cin >> choice;

        if (choice == 0) {
            break; // Exit the program.
        } else if (choice == 1) {
            int priority;
            string name;
            cin >> priority >> name;

            // Add the patient to the priority queue.
            emergencyQueue.push({priority, name});
        } else if (choice == 2) {
            if (!emergencyQueue.empty()) {
                // Treat the patient with the highest priority.
                Patient treatedPatient = emergencyQueue.top();
                emergencyQueue.pop();
                cout << "Patient with priority " << treatedPatient.priority
                     << " and name " << treatedPatient.name << " has been treated." << endl;
            } else {
                cout << "Error: Queue is empty." << endl;
            }
        } else {
            cout << "Invalid choice." << endl;
        }
    }

    return 0;
}

