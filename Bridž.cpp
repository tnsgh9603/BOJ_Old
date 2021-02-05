#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int N;
    cin >> N;
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        string temp;
        cin >> temp;
        for (int j = 0; j < temp.size(); j++) {
            switch (temp[j]) {
            case 'A':
                sum += 4;
                break;
            case 'K':
                sum += 3;
                break;
            case 'Q':
                sum += 2;
                break;
            case 'J':
                sum += 1;
                break;
            default:
                break;
            }
        }
    }
    cout << sum;
    return 0;
}