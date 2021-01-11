#include <iostream>
#include <map>
using namespace std;
map<int, int> mp;
int main() {
    int N, M, K;
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> M >> K;
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        mp[a] = b;
    }
    for (int i = 0; i < M; ++i) {
        int oper, key, val;
        cin >> oper >> key;
        // 새로운 데이터 삽입
        if (oper == 1) {
            cin >> val;
            mp[key] = val;
        }
        if (!mp.count(key)) {
            // l에는 key 이상의 첫 번째 값의 위치
            auto l = mp.lower_bound(key);
            // r에는 key 이상의 첫 번째 값의 위치
            auto r = mp.lower_bound(key);
            int a = -1, b = -1;
            // l미만의 값이 존재한다면
            if (l != mp.begin()) {
                a = (--l)->first;
            }
            // r초과의 값이 존재한다면
            if (r != mp.end()) {
                b = r->first;
            }
            // a와 key값의 차이가 K보다 큰 경우
            if (abs(a - key) > K) {
                a = -1;
            }
            // b와 key값의 차이가 K보다 큰 경우
            if (abs(b - key) > K) {
                b = -1;
            }
            // a,b 둘다 key값과의 차이가 K이하일 때
            if (a != -1 && b != -1) {
                // 해당 키 값이 두 개 이상 존재하는 경우
                if (abs(a - key) == abs(b - key)) {
                    key = -2;
                }
                // 차이가 가장 작은 key를 고름
                else if (abs(a - key) < abs(b - key)) {
                    key = a;
                }
                else if (abs(a - key) > abs(b - key)) {
                    key = b;
                }
            }
            // a만 조건을 만족하는 경우
            else if (a != -1) {
                key = a;
            }
            // b만 조건을 만족하는 경우
            else if (b != -1) {
                key = b;
            }
            // 해당 키 값이 없는 경우
            else {
                key = -1;
            }
        }
        if (oper == 2) {
            cin >> val;
            // 키 값에 해당하는 값이 없을 경우 무시
            if (key == -1) {
                continue;
            }
            mp[key] = val;
        }
        if (oper == 3) {
            // 키 값에 해당하는 값이 없을 경우 무시
            if (key == -1) {
                cout << -1 << '\n';
            }
            // 해당하는 키 값이 2개 이상 존재하는 경우
            else if (key == -2) {
                cout << '?' << '\n';
            }
            else {
                cout << mp[key] << '\n';
            }
        }
    }
}