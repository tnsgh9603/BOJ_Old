#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n; 
    cin >> n;
    vector<int> arr;
    int cand = n, cnt = 1;
    while (cand != 1) {
        if (cand % 2 == 0) {
            cand = cand / 2;
        }
        else {
            cand = cand * 3 + 1;
        }
        cnt++;
    }
    cout << cnt;
    return 0;
}