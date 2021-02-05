#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int N;
    cin >> N;
    while (N--) {
        long long a, b, c;
        string cmd, temp;
        cin >> a >> cmd >> b >> temp >> c;
        bool iscorrect = 0;
        if (cmd == "+") {
            iscorrect = (a + b == c);
        }
        if (cmd == "-") {
            iscorrect = (a - b == c);
        }
        if (cmd == "*") {
            iscorrect = (a * b == c);
        }
        if (cmd == "/") {
            iscorrect = (a / b == c);
        }
        iscorrect ? cout << "correct\n" : cout << "wrong answer\n";
    }
    return 0;
}
