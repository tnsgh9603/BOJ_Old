#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;

// second�� �������� �������� ����, second�� ���� ���� ��� first�� �������� �������� ����
bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second < b.second) {
        return true;
    }
    else {
        if (a.second == b.second) {
            return a.first < b.first;
        }
        return false;
    }
}

int main() {
    int t;
    cin >> t;
    for (int k = 1; k <= t; k++) {
        int n, m;
        cin >> n >> m;

        pair<int, int> student[1001];
        bool chosen[1001] = { 0, };
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            student[i] = make_pair(a, b);
        }
        sort(student, student + m, cmp);
        int ans = 0;

        for (int i = 0; i < m; i++) {
            // a,b �� a���� ���� ����� index��, �̹� ���ù��� ���� ���¶�� index��° å�� �л����� �ش�.
            for (int j = student[i].first; j <= student[i].second; j++) {
                if (!chosen[j]) {
                    chosen[j] = true; // å�� ���� �л����� ���ù���
                    ans++;
                    break;
                }
            }
        }
        cout << ans << endl;
        memset(chosen, 0, sizeof(chosen));
        memset(student, 0, sizeof(student));
    }
    return 0;
}