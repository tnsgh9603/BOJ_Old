#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n; 
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        for (auto& i : s) {
            if (i == '-') {
                i = ' ';
            }
        }
        stringstream in(s);
        string a;
        int b;
        in >> a >> b;
        int sum = 0, temp = 1;
        for (int i = a.size() - 1; i >= 0; i--) {
            sum += (a[i] - 'A') * temp;
            temp *= 26;
        }
        cout << (abs(b - sum) <= 100 ? "nice" : "not nice") << '\n';
    }
    return 0;
}