#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int d(int x, int y) {
    return abs("3000111222"[x]-'0' - ("3000111222"[y]-'0')) + abs(("1012012012"[x] - '0' - ("1012012012"[y] - '0')));
}
int main() {
    int h, m;
    scanf("%d:%d", &h, &m);
    int a = 9999, ah, am;
    for (int i = h; i <= 99; i += 24) {
        for (int j = m; j <= 99; j += 60) {
            int x = d(i / 10, i % 10) + d(i % 10, j / 10) + d(j / 10, j % 10);
            if (a > x) {
                a = x;
                ah = i;
                am = j;
            }
        }
    }
    printf("%02d:%02d\n", ah, am);
    return 0;
}
