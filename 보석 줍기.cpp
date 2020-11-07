#include <iostream>
#include <vector>
using namespace std;

int answer = 0, jewelry[101]; // jewelry배열에 보석이 있는 섬들을 저장
bool visited[101][1 << 15]; // [1<<15]로 주운 보석들을 체크
vector <pair<int,int>> graph[101]; // [101]에서는 시작 섬, pair의 첫 번째 요소는 도착 섬,
// 두 번째 요소는 시작 섬과 도착 섬을 잇는 다리를 지나갈 때, 들고 있을 수 있는 최대 보석 수
void dfs(int current, int bit, int cnt) {
	// 다시 1에 도착했을 때, answer의 최대값 계속 갱신
	if (current == 1 && answer < cnt) {
		answer = cnt;
	}
	// 방문 표시
	visited[current][bit] = true;

	for (pair<int,int> next : graph[current]) {
		// 보석을 들고 다리를 지나갈 수 있는 보석의 최대량보다 현재 들고 있는 보석의 양이 더 많은 경우 제외
		if (next.second < cnt) {
			continue;
		}
		// 해당 지점을 방문한 적이 없다면 방문 (보석이 있는 섬인데 보석을 안 주울 경우 + 보석이 없는 섬일 경우)
		if (!visited[next.first][bit]) {
			dfs(next.first, bit, cnt);
		}
		// 보석이 있는 섬을 방문 
		if (jewelry[current]) {
			// 보석을 들고 다리를 지나갈 수 있는 보석의 최대량보다 현재 들고 있는 보석의 양이 더 많은 경우 제외  
			if (next.second < cnt + 1) {
				continue;
			}
			// 다리를 지날 수 있고, 같은 보석을 들고 해당 지점을 방문한 적이 없다면
			if (!visited[next.first][bit | (1 << jewelry[current])]) {
				dfs(next.first, bit | (1 << jewelry[current]), cnt + 1);
			}
		}
	}
}
int main() {
	// n : 섬의 갯수, m : 다리의 갯수, K : 보석이 있는 섬의 갯수
	int n, m, K;
	cin >> n >> m >> K;
	int from, to, temp, jewelrycnt = 1;
	for (int i = 0; i < K; i++) {
		cin >> temp;
		// jewelry배열에 보석이 있는 섬들을 저장
		// 보석의 번호를 jewelrycnt++를 통해 임의로 부여함
		jewelry[temp] = jewelrycnt++;
	}
	for (int i = 0; i < m; i++) {
		// temp -> 다리를 건널 때 들고 있을 수 있는 최대 보석의 개수
		cin >> from >> to >> temp;
		// 양방향으로 
		graph[from].push_back(make_pair(to, temp));
		graph[to].push_back(make_pair(from, temp));
	}
	graph[1].push_back(make_pair(1,14));

	dfs(1, 0, 0);
	cout << answer;
	return 0;
}