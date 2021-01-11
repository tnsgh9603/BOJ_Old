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
        //�ʱ�ȭ �۾�
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
                // �������� ����
                in[b]--, in[a]++;
            }
            else {
                arr[b][a] = 0;
                arr[a][b] = 1;
                // �������� ����
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
		cin >> vec[i]; // ��� ������ vec�� ����
	}
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			arr[vec[i]][vec[j]] = 1;
			// arr[i][j] = 1�̸� i���� j�� �ڿ� ������(i�� j���� ������ ����),
			// �׷��� �ʴٸ� i�� �ڿ� ������ ���� �ǹ�(j�� i���� ������ ����)
			// ��, �� ��ȣ ���� ������ ���� �� �������� ����
		}
	}
	int M;
	cin >> M;
	while (M--) {
		int a, b;
		cin >> a >> b;
		swap(arr[a][b], arr[b][a]);
		// �ش� �� ��ȣ ���� ���� ���踦 �ٲ�
	}
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (arr[vec[j]][vec[i]]) {
				// arr���� ���� ���踦 �ٲپ�����
				// vec�� ��� ������ �������� ����
				swap(vec[i], vec[j]);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (arr[vec[j]][vec[i]]) {
				// �� �ٲپ��־��µ��� ���������� ������ �� �Ǿ��ִٸ� IMPOSSIBLE ���
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