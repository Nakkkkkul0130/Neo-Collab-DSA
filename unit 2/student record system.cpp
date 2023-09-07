#include <iostream>

// Define a class for the student node
class StudentNode {
public:
    int student_id;
    StudentNode* next;

    StudentNode(int id) : student_id(id), next(nullptr) {}
};

// Function to create a singly linked list of student records
StudentNode* createStudentRecords(int n, int* studentIds) {
    if (n == 0) {
        return nullptr; // Return nullptr if no students
    }

    // Create the first node with the first student ID
    StudentNode* head = new StudentNode(studentIds[0]);
    StudentNode* current = head;

    // Create the rest of the nodes
    for (int i = 1; i < n; ++i) {
        StudentNode* newNode = new StudentNode(studentIds[i]);
        current->next = newNode;
        current = newNode;
    }

    return head;
}

// Function to delete the first student record from the linked list
StudentNode* deleteFirstStudent(StudentNode* head) {
    if (head == nullptr) {
        return nullptr;
    }

    StudentNode* newHead = head->next;
    delete head;
    return newHead;
}

// Function to print the remaining student IDs
void printStudentRecords(StudentNode* head) {
    StudentNode* current = head;
    while (current) {
        std::cout << current->student_id << " ";
        current = current->next;
    }
}

int main() {
    // Input: Number of students and their IDs
    int n;
    std::cin >> n;
    int* studentIds = new int[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> studentIds[i];
    }

    // Create the linked list
    StudentNode* head = createStudentRecords(n, studentIds);

    // Delete the first student record
    head = deleteFirstStudent(head);

    // Print the remaining student IDs
    printStudentRecords(head);

    // Clean up memory
    while (head) {
        StudentNode* temp = head;
        head = head->next;
        delete temp;
    }

    delete[] studentIds;

    return 0;
}
