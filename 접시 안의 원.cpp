#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int T;
    cin >> T;
    float half = (float)T / 2.0;
    cout << (int)(half * half + 0.5) << "\n";
    return 0;
}