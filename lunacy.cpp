#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    while (1) {
        double t;
        cin >> t;
        if (t == -1.0) {
            break;
        }
        cout << fixed << setprecision(2) << "Objects weighing " << t << " on Earth will weigh " << t * 0.167 << " on the moon.\n";
    }
    return 0;
}