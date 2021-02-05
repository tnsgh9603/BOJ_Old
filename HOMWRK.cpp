#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int N;
    cin >> N;
    while (N--) {
        int n; 
        cin >> n;
        while (n--) {
            int a, b; 
            cin >> a >> b;
            cout << a + b << ' ' << a * b << '\n';
        }
    }
    return 0;
}