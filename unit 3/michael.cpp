#include <iostream>
#include <deque>

using namespace std;

int main() {
    deque<int> stockPrices;

    int price;
    while (true) {
        cin >> price;
        if (price == -1) {
            break;
        }
        stockPrices.push_back(price);
    }

    if (stockPrices.empty()) {
        cout << "The deque is empty." << endl;
    } else {
        int minPrice = stockPrices.front();
        for (int p : stockPrices) {
            if (p < minPrice) {
                minPrice = p;
            }
        }
        cout << "The minimum element in the deque is: " << minPrice << endl;
    }

    return 0;
}

