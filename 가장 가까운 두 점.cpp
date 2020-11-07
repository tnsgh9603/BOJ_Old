#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>

using namespace std;
#define INF 2000000000

vector<pair<int, int>> vec;
map<pair<int, int>, int> m;

int getDist(pair<int, int> a, pair<int, int> b){
	int x1 = a.first;
	int y1 = a.second;
	int x2 = b.first;
	int y2 = b.second;
	return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

int main(){
	int n; 
	cin >> n;
	for (int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		vec.push_back({ x,y });
	}
	
	// x축 정렬을 하는 이유 ?
	// x축 정렬을 통해 x의축의 차이만으로 최대값 후보에서 여러 점들을 제외 시킬 수 있다.
	sort(vec.begin(), vec.end());
	
	// {y,x}으로 insert한 이유?
	// dx를 통해 if문으로 x축과의 거리는 처리 하였고,
	// map에 남아잇는 점들중에서 y축으로 lower_bound, upper_bound를 하기 위함이다.
	// = 0 인이 이유?
	// 어떤 값이든 크게 상관없지만 , INF보단 작고, -INF보단 커야한다.( lower_bound, upper_bound를 위해 )
	m[{vec[0].second, vec[0].first}] = 0;
	m[{vec[1].second, vec[1].first}] = 0;
	int ans = getDist(vec[0], vec[1]);
	
	// pos = 0 부터, i = 2 부터인 이유?
	// 편의상 첫번째점과 두번째점을 (x축 정렬 기준 ) 을 기준으로 잡았다.
	// 밑의 코드의 for문을 돌리는대신 기준을 잡았다고 보면 된다.
	/*
	for(int i = 0 ; i < 2; i ++){
	...
	}
	*/
	int pos = 0;
	for (int i = 2; i < n; i++) {
		// pos부터 i-1번까지 i번째점과 비교를 한다.
		while (pos < i) {
			// x축간의 거리 차이
			int dx = vec[i].first - vec[pos].first;
			// pos( i 점 기준으로 현재 map 있는 가장 왼쪽 점 ) 과 i번째 점간의 x축 거리가
			// 더 작다면 pos점은 여전히 후보에 포함될 수 있다.
			if (dx * dx <= ans) break;
			// pos(i 점 기준으로 현재 map 있는 가장 왼쪽 점) 과 i번째 점간의 x축 거리가
			// 더 크다면 pos점은 더이상 더 작은 ans값을 만들어내지 못한다.( 후보에서 제외된다 )
			m.erase({ vec[pos].second,vec[pos].first });
			pos++;
		}
		// getDist 는 sqrt를 없이 반환했음으로...
		int dis = sqrt(ans);
		// map에 남아있는 점들중에서
		// 현재 ans보다 작아 질 수 있는 후보 점들을 확인 하기위해 left, right를 찾고
		auto left = m.lower_bound({ vec[i].second - dis, -INF });
		auto right = m.upper_bound({ vec[i].second + dis, INF });
		// ans 갱신
		for (auto l = left; l != right; l++) {
			ans = min(ans, getDist({ l->first.second,l->first.first }, vec[i]));
		}
		// i번째점은 당연히 뒤에 확인할게 있음으로 후보 점이 된다.
		m[{vec[i].second, vec[i].first}] = 0;
	}
	cout << ans << "\n";
	return 0;
}