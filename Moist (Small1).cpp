#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int N; 
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int n, cnt = 0;
        cin >> n; 
        cin.ignore();
        priority_queue<string> PQ;
        while (n--) {
            string s; getline(cin, s);
            if (!PQ.empty() && PQ.top() > s) {
                cnt++;
            }
            PQ.push(s);
        }
        cout << "Case #" << i << ": " << cnt << '\n';
    }
    return 0;
}
