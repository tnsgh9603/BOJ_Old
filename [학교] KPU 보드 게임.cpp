#include <iostream>
#include <vector>
using namespace std;
vector <char> locate;
int main() {
	int N, M, roll;
	char location;
	cin >> N >> M;
	locate.push_back(0);
	for (int i = 1; i <= N; i++) {
		cin >> location;
		locate.push_back(location);
	}
	int dnlcl = 1, count = 1;
	for (int i = 1; i <= M; i++) {
		cin >> roll;
		if (locate[dnlcl] == '+') {
			if (dnlcl + roll <= N) {
				dnlcl += roll;
			}
		}
		else if (locate[dnlcl] == '-') {
			if (dnlcl - roll >= 1) {
				dnlcl -= roll;
			}
		}
		if (dnlcl == 1) {
			count++;
		}
	}
	cout << count;
	return 0;
}