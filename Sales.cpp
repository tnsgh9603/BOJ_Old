#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int N;
    cin >> N;
    while (N--) {
        int n, t = 0; 
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            for (int j = 0; j < i; j++) {
                t += v[j] <= v[i];
            }
        }
        cout << t << '\n';
    }
    return 0;
}