// 세그먼트 트리
#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;
int N;
int p[100001];
vector<int> range;
int init(int left, int right, int node) {
	if (left == right) { // 가장 아래(리프 노드)까지 내려왔다는 뜻
		return range[node] = left; // 인덱스를 저장
	}

	/* << 현재 노드의 번호가 node 일 때 >>
	노드의 왼쪽 자식 배열 번호 :: node * 2
	노드의 오른쪽 자식 배열 번호 :: node * 2  + 1 */
	int mid = (left + right) / 2;
	int lo = init(left, mid, node * 2);
	int hi = init(mid + 1, right, node * 2 + 1);

	if (p[lo] <= p[hi]) {
		return range[node] = lo; // 구간 내에 최소값을 가지는 인덱스의 위치를 저장
	}
	else {
		return range[node] = hi;
	}
}

int query(int left, int right, int node, int nodeLeft, int nodeRight) {
	if (left <= nodeLeft && nodeRight <= right) {
		return range[node]; // 구하는 범위 내에 있을 경우 반환
	}
	if (nodeRight < left || right < nodeLeft) {
		return -1; // 범위 벗어나면 -1
	}
	int mid = (nodeLeft + nodeRight) / 2;
	int lo = query(left, right, node * 2, nodeLeft, mid); // (nodeLeft, mid) 사이의 최소값 인덱스
	int hi = query(left, right, node * 2 + 1, mid + 1, nodeRight); // (mid+1, nodeRight) 사이의 최소값 인덱스

	if (lo == -1) {
		return hi;
	}
	if (hi == -1) {
		return lo;
	}
	if (p[lo] <= p[hi]) {
		return lo; // 최소값을 갖는 인덱스 위치 반환.
	}
	else {
		return hi;
	}
}

long long solve(int left, int right) {
	if (left > right) {
		return -1; // 종료 조건
	}
	int loIdx = query(left, right, 1, 0, N - 1); // (left,right) 범위의 최소값을 갖는 인덱스 구하기
	long long res = (long long)((long long)right - (long long)left + 1) * p[loIdx]; // (left, right) 범위를 모두 포함하게 만들 수 있는 직사각형 넓이

	if (loIdx != left) {
		res = max(res, solve(left, loIdx - 1)); // (left, loIdx-1) 까지 범위로 만들 수 있는 직사각형의 최대 넓이 최신화
	}
	if (loIdx != right) {
		res = max(res, solve(loIdx + 1, right)); // (loIdx+1, right) 범위
	}
	return res; // 최대 넓이 반환
}

int main() {
	while (1) {
		cin >> N;
		if (!N) {
			return 0;
		}
		range.resize(N * 4);
		for (int i = 0; i < N; i++) {
			cin >> p[i];
		}
		init(0, N - 1, 1); // 세그먼트 트리 초기화
		cout << solve(0, N - 1) << "\n"; // 정답 출력
		memset(p, 0, sizeof(p));
	}
	return 0;
}
/*
// 위 문제에서 long long만 붙여주고 0을 입력하지 않을때까지 무한 반복, 돌릴때마다 스택과 배열 초기화만 해주면 된다.
#include <iostream>
#include <stack>
#include <algorithm>
#include <memory.h>
using namespace std;

int arr[1000001] = { 0, };
stack<int> q;
int main() {
    while (1) {
        int N;
        long long ans = 0;
        cin >> N;
        if (N == 0) {
            return 0;
        }

        for (int i = 1; i <= N; i++) {
            cin >> arr[i];
        }
        q.push(0);
        for (int i = 1; i <= N + 1; i++) {
            while (!q.empty() && arr[q.top()] > arr[i]) {
                int a = q.top();
                long long height = arr[q.top()];
                q.pop();
                long long  width = i - q.top() - 1;
                ans = max(ans, height * width);
            }
            q.push(i);
        }
        cout << ans << "\n";
        while (!q.empty()) {
            q.pop();
        }
        memset(arr, 0, sizeof(arr));
    }
    return 0;
}
*/