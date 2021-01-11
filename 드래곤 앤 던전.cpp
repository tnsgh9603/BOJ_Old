#include <iostream>
#include <vector>
#include <tuple>
#include <limits.h>
using namespace std;
typedef long long ll;
vector<pair<ll,pair<ll,ll>>> vec;
int main() {
    ll N, H_ATK, ans, a, b, c, low = 0, high = LONG_MAX;
    cin >> N >> H_ATK;
    for (int i = 0; i < N; i++) {
        cin >> a >> b >> c;
        // a가 1이면 몬스터가 있는 방, a가 2면 포션방
        // a가 1이면 b는 몬스터의 공격력, c는 몬스터의 체력
        // a가 2면 b는 포션이 올려주는 공격력량, c는 포션의 회복량
        vec.push_back({ a,{b,c} });
    }
    while (low + 1 < high) {
        // HP는 내 체력
        ll ATK = H_ATK, mid = (low + high) >> 1, HP = mid;
        for (int i = 0; i < N; i++) {
            // 몬스터 방이면
            if (vec[i].first == 1) {
                ll x = (vec[i].second.second % ATK);
                // 딱뎀으로 죽일 수 있는 경우
                if (x == 0) {
                    // 몬스터의 체력을 용사의 공격력으로 나누면 용사가 몬스터를 처치하기위해 필요한 공격횟수가 나온다.
                    // 용사가 선빵치므로 (용사의 공격횟수 - 1) * 몬스터의 공격력 만큼 용사의 HP가 감소한다.
                    HP -= (vec[i].second.second / ATK - 1) * vec[i].second.first;
                }
                // 딸피가 남아있는 경우 막타를 쳐야한다.
                else {
                    HP -= (vec[i].second.second / ATK) * vec[i].second.first;
                }
            }
            // 포션방이면
            else {
                // 공격력 상승 및 체력 회복
                ATK += vec[i].second.first;
                HP += vec[i].second.second;
                // 최대 HP보다 더 회복할 수는 없음
                if (HP >= mid) {
                    HP = mid;
                }
            }
            // 용사가 체력이 부족해서 죽음 ㅠㅠ
            if (HP <= 0) {
                break;
            }
        }
        // 체력의 여유가 충분한 경우
        if (HP > 0) {
            ans = mid;
            high = mid;
        }
        // YOU DIED
        else {
            low = mid;
        }
    }
    cout << high;
    return 0;
}
