#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    vector<int> v;
    for (int i = 1; i * (i + 1) / 2 < 1000; i++) {
        v.push_back(i * (i + 1) / 2);
    }
    int N; cin >> N;
    while (N--) {
        int n;
        cin >> n;
        bool flag = 0;
        for (int i = 0; i < v.size(); i++) {
            for (int j = i; j < v.size(); j++) {
                for (int k = j; k < v.size(); k++) {
                    if (v[i] + v[j] + v[k] == n) {
                        flag = 1;
                    }
                }
            }
        }
        cout << flag << '\n';
    }
    return 0;
}
