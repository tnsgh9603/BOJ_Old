#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    while (1) {
        string s;
        cin >> s;
        if (s == "0") {
            break;
        }
        int sum = 0;
        for (int i = 0; i < s.size(); ++i) {
            sum += s[i] - '0';
        }
        while (sum >= 10){
            int sum2 = sum;
            sum = 0;
            for (; sum2 > 0; sum2 /= 10) {
                sum += sum2 % 10;
            }
        }
        cout << sum << "\n";
    }
}
