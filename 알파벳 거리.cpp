#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
int main() {
    fastio;
    int N;
    cin >> N; 
    while (N--) {
        string a, b; 
        cin >> a >> b;
        cout << "Distances: ";
        for (int i = 0; i < a.size(); i++) {
            cout << ((a[i] <= b[i]) ? (b[i] - a[i]) : (b[i] + 26 - a[i])) << ' ';
        }
        cout << '\n';
    }
    return 0;
}
