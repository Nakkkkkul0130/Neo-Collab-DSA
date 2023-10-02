#include <iostream>

using namespace std;

int towerOfWisdom(int n, char source, char auxiliary, char illuminated) {
    if (n == 1) {
        cout << "Move disk 1 from " << source << " to " << illuminated << endl;
        return 1;
    }

    int count1 = towerOfWisdom(n - 1, source, illuminated, auxiliary);
    cout << "Move disk " << n << " from " << source << " to " << illuminated << endl;
    int count2 = towerOfWisdom(n - 1, auxiliary, source, illuminated);

    return count1 + 1 + count2;
}

int main() {
    int n;
    cin >> n;

    int total_moves = towerOfWisdom(n, 'A', 'B', 'C');
    cout << "Total number of times the disk is moved: " << total_moves << endl;

    return 0;
}
