#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int N; 
    cin >> N;
    cout << fixed << setprecision(4);
    while (N--) {
        double n;
        string s;
        cin >> n >> s;
        if (s == "kg") {
            cout << n * 2.2046 << " lb" << '\n';
        }
        else if (s == "lb") {
            cout << n * 0.4536 << " kg" << '\n';
        }
        else if (s == "l") {
            cout << n * 0.2642 << " g" << '\n';
        }
        else {
            cout << n * 3.7854 << " l" << '\n';
        }
    }
    return 0;
}
