#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>
using namespace std;
int t, n, m, a, b;
int arr[501][501], order[501], in[501];
queue<int> q;
vector<int> ans;
int main() {
    cin >> t;
    while (t--) {
        //초기화 작업
        while (!q.empty()) {
            q.pop();
        }
        ans.clear();
        memset(arr, 0, sizeof(arr));
        memset(in, 0, sizeof(in));

        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> order[i];
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                arr[order[i]][order[j]] = 1;
                in[order[j]]++;
            }
        }
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            if (arr[a][b]) {
                arr[a][b] = 0;
                arr[b][a] = 1;
                // 진입차수 갱신
                in[b]--, in[a]++;
            }
            else {
                arr[b][a] = 0;
                arr[a][b] = 1;
                // 진입차수 갱신
                in[a]--, in[b]++;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (!in[i]) {
                q.push(i);
            }
        }
        bool flag = true;
        while (!q.empty()) {
            if (q.size() > 1) {
                flag = false;
                break;
            }
            int now = q.front();
            q.pop();
            ans.push_back(now);
            for (int next = 1; next <= n; next++) {
                if (arr[now][next]) {
                    if (--in[next] == 0) {
                        q.push(next);
                    }
                }
            }
        }
        if (!flag) {
            cout << "?";
        }
        if (ans.size() == n) {
            for (int i = 0; i < n; i++) {
                cout << ans[i] << " ";
            }
        }
        else {
            cout << "IMPOSSIBLE\n";
        }
    }
    return 0;
}

/*
#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;
vector <int> vec;
int arr[501][501];
void sol() {
	memset(arr, 0, sizeof(arr));
	vec.clear();
	int N;
	cin >> N;
	vec.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> vec[i]; // 등수 순으로 vec에 저장
	}
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			arr[vec[i]][vec[j]] = 1;
			// arr[i][j] = 1이면 i보다 j가 뒤에 나오고(i가 j보다 성적이 높다),
			// 그렇지 않다면 i가 뒤에 나오는 것을 의미(j가 i보다 성적이 높다)
			// 즉, 팀 번호 간의 성적이 누가 더 높은지를 저장
		}
	}
	int M;
	cin >> M;
	while (M--) {
		int a, b;
		cin >> a >> b;
		swap(arr[a][b], arr[b][a]);
		// 해당 팀 번호 간의 성적 관계를 바꿈
	}
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (arr[vec[j]][vec[i]]) {
				// arr에서 성적 관계를 바꾸었으니
				// vec도 등수 순으로 오름차순 정렬
				swap(vec[i], vec[j]);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (arr[vec[j]][vec[i]]) {
				// 다 바꾸어주었는데도 성적순으로 정렬이 안 되어있다면 IMPOSSIBLE 출력
				cout << "IMPOSSIBLE\n";
				return;
			}
		}
	}
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << "\n";

}
int main() {
	int t;
	cin >> t;
	while (t--) {
		sol();
	}
}
*/