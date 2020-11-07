#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
int sushi[3000001];
int sushi_kind[3001];
deque<int> dq;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, D, K, C;
    cin >> N >> D >> K >> C;

    for (int i = 0; i < N; i++) {
        cin >> sushi[i];
    }

    int cnt = 0;
    int result = 0;

    //ù ��° ���ú��� K�� ���� �ְ� ���� ����
    for (int i = 0; i < K; i++) {
        dq.push_back(sushi[i]);
        if (!sushi_kind[sushi[i]]++) {
            cnt++;
        }
        result = max(result, cnt);
    }
    //�����̵� ������ ���
    for (int i = 0; i < N - 1; i++) {
        //�� �� ���ø� ����
        dq.pop_front();
        //�ش� ������ ������ ���� ���� ��� cnt�� ����
        if (!(--sushi_kind[sushi[i]])) {
            cnt--;
        }
        //���� ���ø� ���� �ִ´�
        dq.push_back(sushi[(i + K) % N]);
        //���ο� ������� cnt�� �����ش�
        if (!(sushi_kind[sushi[(i + K) % N]])++) {
            cnt++;
        }
        result = max(result, cnt + (sushi_kind[C] == 0));
    }
    cout << result;
    return 0;
}
/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;
vector <int> vec;
int arr[3001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, d, k, c, input;
	cin >> N >> d >> k >> c;
	for (int i = 0; i < N; i++) {
		cin >> input;
		vec.push_back(input);
	}
	int max_cnt = 0;
	for (int i = 0; i < vec.size(); i++) {
		int start = i, cnt = 0, cnt2 = 0;
		for (int q = start; ; q++) {
			if (q == vec.size()) {
				q = 0;
			}
			if (arr[vec[q]] == 0) {
				arr[vec[q]]++;
				cnt++;
			}
			cnt2++;
			if (cnt2 == k) {
				break;
			}
		}
		if (!arr[c]) {
			cnt++;
		}
		max_cnt = max(max_cnt, cnt);
		memset(arr, 0, sizeof(arr));
	}
	cout << max_cnt;
	return 0;
}*/