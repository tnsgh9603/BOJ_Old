// 세그먼트 트리
#include <iostream>
#include <algorithm>
#include <vector>
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
		return -1; // 종료조건
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

int main(){
	cin >> N;
	range.resize(4 * N);
	for (int i = 0; i < N; i++) {
		cin >> p[i];
	}
	
	init(0, N - 1, 1); // 세그먼트 트리 초기화

	cout << solve(0, N - 1); // 정답 출력
	return 0;
}
/* 스택을 이용
#include <iostream>
#include <stack> // 스택을 사용하기 위해
#include <algorithm> // max 함수 사용을 위해
using namespace std;

stack<int> q; 
int arr[100001] = { 0, };
int main() {
	int N, ans = 0; 
	cin >> N; // N은 히스토그램의 가로 칸의 수

	for (int i = 1; i <= N; i++) {
		cin >> arr[i]; // N만큼 입력받아줌
	}

	q.push(0); // 시작 부분을 고려해주기 위해 0을 넣어줌
	for (int i = 1; i <= N + 1; i++){ // 종료 부분을 고려해주기 위해 N+1까지 넣어줌
		while (arr[q.top()] > arr[i]){ // 높이가 작거나 같은 것을 만날 때까지 계속 push 해주고, 
			                           // 높이가 작거나 같은 것을 만나면 사각형의 넓이를 계산해줌
			int height = arr[q.top()]; // 세로 길이 계산
			q.pop();
			int width = i - q.top() - 1; // 가로 길이 계산
			ans = max(ans, height * width); // 사각형의 넓이를 계산해서 원래 있는 것보다 더 크면 갱신
		}
		q.push(i);
	}
	cout << ans;
	return 0;
}*//


/* 
#include <iostream>
using namespace std;
int arr[100001] = { 0, };
int main() {
	int N, max = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < N; i++) {
		int k = 1, q = -1;
		while (arr[i + k] >= arr[i] && i + k < N) {
			k++;
		}
		while (arr[i + q] >= arr[i] && i + q >= 0) {
			q--;
		}
		int ans = arr[i] * (k + abs(q) - 1);
		if (max < ans) {
			max = ans;
		}
	}
	cout << max;
	return 0;
}*/
