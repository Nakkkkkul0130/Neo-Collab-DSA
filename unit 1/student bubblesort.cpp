#include <iostream>
#include <vector>
#include <string>
using namespace std;
void bubble(vector<string>& names) {
    int n = names.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (names[j] > names[j + 1]) {
                swap(names[j], names[j + 1]);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<string> sname(n);
    for (int i = 0; i < n; i++) {
        cin >> sname[i];
    }
    bubble(sname);

    for (const string& name : sname) {
        cout << name << " ";
    }
    cout<<endl;
    
    return 0;
}