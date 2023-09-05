#include <iostream>
using namespace std;
int firstoccurence(const int prices[], int size, int target) {
    int left = 0, right = size - 1, result = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (prices[mid] == target) {
            result = mid;
            right = mid - 1; 
        } else if (prices[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return result;
}

int findLastOccurrence(const int prices[], int size, int target) {
    int left = 0, right = size - 1, result = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (prices[mid] == target) {
            result = mid;
            left = mid + 1;
        } else if (prices[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return result;
}

int main() {
    int size;
    cin >> size;

    int *prices = new int[size];
    for (int i = 0; i < size; ++i) {
        cin >> prices[i];
    }

    int target;
    cin >> target;
    
    int firstOccurrence = firstoccurence(prices, size, target);
    int lastOccurrence = findLastOccurrence(prices, size, target);
    
    if (firstOccurrence != -1 && lastOccurrence != -1) {
        cout << "The first occurrence of " << target << " is at index " << firstOccurrence << "." << endl;
        cout << "The last occurrence of " << target << " is at index " << lastOccurrence << "." << endl;
    } else {
        cout << "Target value " << target << " is not found in the array." << endl;
    }
    
    delete[] prices;

    return 0;
}