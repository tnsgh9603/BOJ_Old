#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
vector<int> vec;
int main() {
    fastio;
    int q;
    for (int i = 0; i < 3; i++) {
        cin >> q;
        vec.push_back(q);
    }
    sort(vec.begin(), vec.end());
    int b = vec[2] - vec[1];
    int a = vec[1] - vec[0];
    if (b == a) {
        cout << vec[2] + b;
    }
    else if (b > a) {
        cout << vec[2] - a;
    }
    else {
        cout << vec[1] - b << endl;
    }
    return 0;
} 