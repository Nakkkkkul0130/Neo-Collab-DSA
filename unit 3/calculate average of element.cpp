#include <iostream>
#include <queue>
#include <iomanip>

using namespace std;

int main() {
    int N;
    cin >> N;

    queue<int> q;
    double sum = 0.0;

    for (int i = 0; i < N; i++) {
        int element;
        cin >> element;
        q.push(element);
        sum += element;
    }

    if (N == 0) {
        cout << "Queue is empty." << endl;
    } else {
        double average = sum / N;
        cout << fixed << setprecision(2) << average << endl;
    }

    return 0;
}
