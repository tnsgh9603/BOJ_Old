#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;
vector <int> vec;
bool arr[1001];
int cnt = 0;

void cycle1(int a) {
	if (!arr[a]) {
		arr[a] = 1;
		return cycle1(vec[a]);
	}
	else {
		return;
	}
}
void cycle2(int a) {
	cout << a;
	if (!arr[a]) {
		cout << " ";
		arr[a] = 1;
		return cycle2(vec[a]);
	}
	else {
		return;
	}
}

int main() {
	int N, input;
	cin >> N;
	vec.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> input;
		vec[i] = input;
	}
	for (int i = 1; i <= N; i++) {
		if (!arr[i]) {
			cycle1(i);
			cnt++;
		}
	}
	memset(arr, 0, sizeof(arr));
	cout << cnt << "\n";
	for (int i = 1; i <= N; i++) {
		if (!arr[i]) {
			cycle2(i);
			cout << "\n";
		}
	}
	return 0;
}