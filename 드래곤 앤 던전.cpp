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
        // a�� 1�̸� ���Ͱ� �ִ� ��, a�� 2�� ���ǹ�
        // a�� 1�̸� b�� ������ ���ݷ�, c�� ������ ü��
        // a�� 2�� b�� ������ �÷��ִ� ���ݷ·�, c�� ������ ȸ����
        vec.push_back({ a,{b,c} });
    }
    while (low + 1 < high) {
        // HP�� �� ü��
        ll ATK = H_ATK, mid = (low + high) >> 1, HP = mid;
        for (int i = 0; i < N; i++) {
            // ���� ���̸�
            if (vec[i].first == 1) {
                ll x = (vec[i].second.second % ATK);
                // �������� ���� �� �ִ� ���
                if (x == 0) {
                    // ������ ü���� ����� ���ݷ����� ������ ��簡 ���͸� óġ�ϱ����� �ʿ��� ����Ƚ���� ���´�.
                    // ��簡 ����ġ�Ƿ� (����� ����Ƚ�� - 1) * ������ ���ݷ� ��ŭ ����� HP�� �����Ѵ�.
                    HP -= (vec[i].second.second / ATK - 1) * vec[i].second.first;
                }
                // ���ǰ� �����ִ� ��� ��Ÿ�� �ľ��Ѵ�.
                else {
                    HP -= (vec[i].second.second / ATK) * vec[i].second.first;
                }
            }
            // ���ǹ��̸�
            else {
                // ���ݷ� ��� �� ü�� ȸ��
                ATK += vec[i].second.first;
                HP += vec[i].second.second;
                // �ִ� HP���� �� ȸ���� ���� ����
                if (HP >= mid) {
                    HP = mid;
                }
            }
            // ��簡 ü���� �����ؼ� ���� �Ф�
            if (HP <= 0) {
                break;
            }
        }
        // ü���� ������ ����� ���
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
