#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
int main() {
    fastio;
    int N;
    for (cin >> N; N--;) {
        vector<int> v(5);
        for (int i = 0; i < 5; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        if (v[3] - v[1] >= 4) {
            cout << "KIN\n";
        }
        else {
            cout << v[1] + v[2] + v[3] << '\n';
        }
    }
    return 0;
}
