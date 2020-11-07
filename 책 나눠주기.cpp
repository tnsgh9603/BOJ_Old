#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;

// second를 기준으로 오름차순 정렬, second가 서로 같을 경우 first를 기준으로 오름차순 정렬
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
            // a,b 중 a에서 가장 가까운 index를, 이미 선택받지 않은 상태라면 index번째 책을 학생에게 준다.
            for (int j = student[i].first; j <= student[i].second; j++) {
                if (!chosen[j]) {
                    chosen[j] = true; // 책이 이제 학생에게 선택받음
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