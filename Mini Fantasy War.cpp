#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int test_case;
    cin >> test_case;
    for (int t = 0; t < test_case; t++) {
        int hp, mp, attack, defense, h, m, a, d;
        cin >> hp >> mp >> attack >> defense >> h >> m >> a >> d;
        hp = max(1, hp + h);
        mp = max(1, mp + m);
        attack = max(0, attack + a);
        defense += d;
        cout << hp + 5 * mp + 2 * attack + 2 * defense << "\n";
    }
    return 0;
}