#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef pair<int, int> pii;
vector<pair<pii, pii> > vc;
bool comp(const pair<pii, pii>& p, const pair<pii, pii>& q) {
    int a = p.first.first;
    int b = p.first.second;
    int c = p.second.first;

    int aa = q.first.first;
    int bb = q.first.second;
    int cc = q.second.first;

    if (a == aa) {
        if (b == bb) {
            return c < cc;
        }
        return b < bb;
    }
    return a > aa;
}
int main() {
    fastio;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        vc.push_back({ {a,b},{c,i} });
    }
    sort(vc.begin(), vc.end(), comp);
    cout << vc[0].second.second;
    return 0;
}