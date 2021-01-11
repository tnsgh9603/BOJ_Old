#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n, w, h;
    cin >> n >> w >> h;
    double tmp = sqrt(w * w + h * h);
    for (int i = 0; i < n; i++) {
        int stick;
        cin >> stick;
        if (stick <= tmp)
            cout << "DA" << '\n';
        else
            cout << "NE" << '\n';
    }
    return 0;
}