#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int n, b, input;
    cin >> n >> b;
    for (int k = 1; k <= b; k++) {
        vector<int> a;
        for (int i = 0; i < n; i++) {
            cin >> input;
            a.push_back(input);
        }
        if (next_permutation(a.begin(), a.end())) {
            for (int i = 0; i < a.size(); i++) {
                cout << a[i] << ' ';
            }
        }
        cout << '\n';
    }
}