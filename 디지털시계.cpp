#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    for (int i = 1; i <= 3; i++) {
        int sh, sm, ss, fh, fm, fs;
        int cnt = 0;
        scanf("%d:%d:%d %d:%d:%d", &sh, &sm, &ss, &fh, &fm, &fs);
        int h = sh, m = sm, s = ss;
        while (1) {
            int clock = h * 10000 + m * 100 + s;
            if (clock % 3 == 0) {
                cnt++;
            }
            if (h == fh && m == fm && s == fs) {
                break;
            }
            s++;
            if (s == 60) {
                s = 0;
                m++;
            }
            if (m == 60) {
                m = 0;
                h++;
            }
            if (h == 24) {
                h = 0;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}
