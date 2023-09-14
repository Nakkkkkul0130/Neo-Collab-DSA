#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Packet {
    int priority;
    string data;

    // Overloading the '<' operator to compare packets based on priority.
    bool operator<(const Packet& other) const {
        return priority > other.priority; // Lower priority comes first.
    }
};

int main() {
    int capacity, numPackets;
    cin >> capacity >> numPackets;

    priority_queue<Packet> packetQueue;

    cout << "Processing packets based on priority:" << endl;

    for (int i = 0; i < numPackets; i++) {
        int priority;
        string data;
        cin >> priority;
        cin.ignore(); // Clear the newline character from the previous input
        getline(cin, data);
        packetQueue.push({priority, data});
    }

    while (!packetQueue.empty()) {
        Packet packet = packetQueue.top();
        packetQueue.pop();
        cout << "Processing packet with priority " << packet.priority << " and data: " << packet.data << endl;
    }

    return 0;
}

