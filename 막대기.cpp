#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int stick[100001];
int main() {
    fastio;
    int n, answer = 1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> stick[i];
    }
    int pivot = stick[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        if (stick[i] > pivot) {
            answer++;
            pivot = stick[i];
        }
    }
    cout << answer;
    return 0;
}
