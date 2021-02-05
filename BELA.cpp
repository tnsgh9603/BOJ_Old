#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int N;
    char c;
    cin >> N >> c;
    int sum = 0;
    for (int i = 0; i < 4 * N; i++) {
        string s;
        cin >> s;
        switch (s[0]) {
        case 'A':
            sum += 11;
            break;
        case 'K':
            sum += 4;
            break;
        case 'Q':
            sum += 3;
            break;
        case 'J':
            if (s[1] == c) {
                sum += 20;
            }
            else {
                sum += 2;
            }
            break;
        case 'T':
            sum += 10;
            break;
        case '9':
            if (s[1] == c) {
                sum += 14;
            }
            break;
        default:
            break;
        }
    }
    cout << sum;
    return 0;
}

