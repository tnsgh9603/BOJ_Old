#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
char p[1003], m[10], ans[10];
int main() {
    fastio;
    int b;
    cin >> b;
    long long a, d, copy;
    while (b) {
        cin >> p >> m;
        a = 0; d = 0;
        // d -> m�� 10������ ǥ���� ��
        for (int i = 0; i < strlen(m); ++i) {
            d = d * b + (m[i] - '0');
        }
        // a -> p % m�� 10������ ��Ÿ�� ��
        for (int j = 0; j < strlen(p); ++j) {
            a = a * b + (p[j] - '0');
            if (a >= d) { 
                a %= d;
            }
        }
        int l = 0;
        copy = a;
        // �������� 0�̸� �ٷ� 0 ���
        if (!copy) {
            cout << "0\n";
            cin >> b;
            continue;
        }
        // l -> �������� 2������ ǥ������ �� �ڸ���
        while (copy >= b) {
            copy /= b; 
            ++l;
        }
        copy = a;
        ans[l + 1] = 0;
        while (copy > 0) {
            ans[l] = '0' + (copy % b);
            copy /= b;
            --l;
        }
        cout << ans << "\n";
        cin >> b;
    }
    return 0;
}