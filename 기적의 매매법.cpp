#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
vector<int> v(14);
int sol_1(int money) {
    int cnt = 0;
    for (int i = 0; i < 14; i++) {
        cnt += money / v[i];
        money %= v[i];
    }
    return money + cnt * v.back();
}

int sol_2(int money) {
    int cnt = 0;
    for (int i = 3; i < 14; i++) {
        if (v[i - 3] > v[i - 2] && v[i - 2] > v[i - 1] && v[i - 1] > v[i]) {
            cnt += money / v[i];
            money %= v[i];
        }
        if (v[i - 3] < v[i - 2] && v[i - 2] < v[i - 1] && v[i - 1] < v[i]) {
            money += cnt * v[i];
            cnt = 0;
        }
    }
    return money + cnt * v.back();
}

int main() {
    fastio;
    int n;
    cin >> n;
    for (int i = 0; i < 14; i++) {
        cin >> v[i];
    }
    int a = sol_1(n), b = sol_2(n);
    if (a > b) {
        cout << "BNP" << '\n';
    }
    else if (a < b) {
        cout << "TIMING" << '\n';
    }
    else {
        cout << "SAMESAME" << '\n';
    }
    return 0;
}