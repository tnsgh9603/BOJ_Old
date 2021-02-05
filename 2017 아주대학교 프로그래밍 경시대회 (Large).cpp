#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n, a, b, c, re = 1, score[3];
    cin >> n >> score[0] >> score[1] >> score[2];
    for (int i = 2; i <= n; i++) {
        cin >> a >> b >> c;
        if (score[0] < a) {
            re = i;
        }
        else if (score[0] == a && score[1] > b) {
            re = i;
        }
        else if (score[0] == a && score[1] == b && score[2] > c) {
            re = i;
        }
        if (re == i) {
            score[0] = a;
            score[1] = b;
            score[2] = c;
        }
    }
    cout << re;
    return 0;
}