#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    if (N == 0) {
        cout << "Queue is empty" << endl;
        return 0;
    }

    priority_queue<double, vector<double>, greater<double>> minHeap;
    queue<double> originalQueue;

    for (int i = 0; i < N; i++) {
        double element;
        cin >> element;
        minHeap.push(element);
        originalQueue.push(element);
    }

    double smallest = minHeap.top();
    minHeap.pop();

    while (!originalQueue.empty()) {
        double front = originalQueue.front();
        originalQueue.pop();
        if (front != smallest) {
            cout << front << " ";
        }
    }

    cout << endl;

    return 0;
}
