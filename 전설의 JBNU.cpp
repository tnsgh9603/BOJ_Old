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
        // ���ο� ������ ����
        if (oper == 1) {
            cin >> val;
            mp[key] = val;
        }
        if (!mp.count(key)) {
            // l���� key �̻��� ù ��° ���� ��ġ
            auto l = mp.lower_bound(key);
            // r���� key �̻��� ù ��° ���� ��ġ
            auto r = mp.lower_bound(key);
            int a = -1, b = -1;
            // l�̸��� ���� �����Ѵٸ�
            if (l != mp.begin()) {
                a = (--l)->first;
            }
            // r�ʰ��� ���� �����Ѵٸ�
            if (r != mp.end()) {
                b = r->first;
            }
            // a�� key���� ���̰� K���� ū ���
            if (abs(a - key) > K) {
                a = -1;
            }
            // b�� key���� ���̰� K���� ū ���
            if (abs(b - key) > K) {
                b = -1;
            }
            // a,b �Ѵ� key������ ���̰� K������ ��
            if (a != -1 && b != -1) {
                // �ش� Ű ���� �� �� �̻� �����ϴ� ���
                if (abs(a - key) == abs(b - key)) {
                    key = -2;
                }
                // ���̰� ���� ���� key�� ��
                else if (abs(a - key) < abs(b - key)) {
                    key = a;
                }
                else if (abs(a - key) > abs(b - key)) {
                    key = b;
                }
            }
            // a�� ������ �����ϴ� ���
            else if (a != -1) {
                key = a;
            }
            // b�� ������ �����ϴ� ���
            else if (b != -1) {
                key = b;
            }
            // �ش� Ű ���� ���� ���
            else {
                key = -1;
            }
        }
        if (oper == 2) {
            cin >> val;
            // Ű ���� �ش��ϴ� ���� ���� ��� ����
            if (key == -1) {
                continue;
            }
            mp[key] = val;
        }
        if (oper == 3) {
            // Ű ���� �ش��ϴ� ���� ���� ��� ����
            if (key == -1) {
                cout << -1 << '\n';
            }
            // �ش��ϴ� Ű ���� 2�� �̻� �����ϴ� ���
            else if (key == -2) {
                cout << '?' << '\n';
            }
            else {
                cout << mp[key] << '\n';
            }
        }
    }
}