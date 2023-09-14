#include <iostream>
#include <deque>

using namespace std;

int main() {
    deque<string> studentsDeque;

    string name;
    while (true) {
        cin >> name;
        if (name == "-1") {
            break;
        }
        studentsDeque.push_back(name);
    }

    int numberOfElements = studentsDeque.size();
    cout << "Number of elements in the deque: " << numberOfElements << endl;

    return 0;
}
