#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> vec;
int arr[10001];
bool visited[4000001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// N은 딱히 안씀
	int N, M, K, idx;
	cin >> N >> M >> K;
	vec.resize(M);
	for (int i = 0; i < M; i++) {
		cin >> vec[i];
	}
	// 오름차순 정렬
	sort(vec.begin(), vec.end());
	for (int i = 0; i < K; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < K; i++) {
		idx = upper_bound(vec.begin(), vec.end(), arr[i]) - vec.begin();
		while (visited[idx]) {
			idx++;
		}
		visited[idx] = true;
		cout << vec[idx] << '\n';
	}
}