#include <iostream>
#include <vector>
#include <algorithm>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n;
vector<vector<int>> v;

bool operator > (const vector<int>& v1, const vector<int>& v2) {
    int mn = min(v1.size(), v2.size());
    for (int i = 0; i < mn; i++) {
        if (v1[i] != v2[i]) return v1[i] > v2[i];
    }
    return v1.size() > v2.size();
}

int main() {
    fastio;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        int t;
        while (cin >> t && t != -1) {
            v[i].push_back(t);
        }
    }
    sort(v.begin(), v.end(),greater<int>());
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << string(j != v[i].size() - 1, ' ');
        }
        cout << string(i != n - 1, '\n');
    }
}