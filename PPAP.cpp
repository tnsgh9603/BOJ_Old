#include <iostream>
#include <string>
using namespace std;
int main() {
	int cnt = 0;
	string sentence;
	cin >> sentence;
	for (int i = 0; i < sentence.length(); i++) {
		if (sentence[i] == 'P') {
			cnt++; 
			continue;
		}
		// 앞에 p가 2번이상 나왓고 다음 것이 P일때
		// 다음 p까지 고려해줬으므로 i++
		// ppap를 p로 고려했으므로  cnt--
		if (cnt >= 2 && sentence[i] == 'A' && sentence[i + 1] == 'P') {
			cnt--;
			i++;
		}
		else {
			cout << "NP";
			return 0;
		}
	}
	// 마지막에 p로 끝나는가?
	if (cnt == 1) {
		cout << "PPAP\n";
	}
	else {
		cout << "NP\n";
	}
	return 0;
}