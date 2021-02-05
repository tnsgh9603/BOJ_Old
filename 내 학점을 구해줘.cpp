#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int test_case;
    cin >> test_case;
    for (int i = 0; i < test_case; i++) {
        int N;
        cin >> N;
        int sumC = 0;
        double sumG = 0.0;
        for (int i = 0; i < N; i++) {
            int c;
            double g;
            cin >> c >> g;
            sumC += c;
            sumG += (c * g);
        }
        printf("%d %.1f\n", sumC, round(10 * sumG / sumC) / 10);
    }
    return 0;
}