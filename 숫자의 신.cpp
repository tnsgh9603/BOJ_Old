#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // sort 함수 사용
using namespace std;
vector<string> ans;

// 문자열 a와 b를 붙였을때 a가 앞에 b가 뒤에 붙었을때가 더 크면 true 리턴
// a가 뒤에 b가 앞에 붙었을때가 더 크면 false 리턴
// 즉 문자열이 더 큰 순으로 리턴
bool cmp(string a, string b) {
	return a + b > b + a;
}

int main() {
	int N, K;
	cin >> K >> N;
	string str = ""; // 비어있는 string 변수
	string tmp;
	for (int i = 1; i <= K; i++) { 
		cin >> tmp;
		// str 보다 tmp의 길이가 길거나 (길이가 더 길다는 말은 자리수가 많다는 말이므로 필연적으로 더 크다) 
		// str와 tmp의 길이가 같으면 tmp가 str보다 클 때 str에 tmp를 넣는다.
		if (str.size() < tmp.size() || (str.size() == tmp.size() && str < tmp)) {
			str = tmp; //str을 큰 수로 바꿔준다.
		}
		ans.push_back(tmp);
	}
	// 그럼 이제 str은 지금까지 입력받은 수중 가장 큰 값이 들어가있다.
	// 이 문제에서 모든 수를 한 번씩은 무조건 사용해야한다.
	// 한 번씩 모든 수를 사용했음에도 수를 더 써야한다면 가장 큰 수를 계속 push해준다.
	for (int i = 1; i <= N - K; i++) {
		ans.push_back(str);
	}
	
	// 정렬
	sort(ans.begin(), ans.end(), cmp);
	
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i];
	}
}