#include <iostream>
using namespace std;
int arr[201];
int main() {
	int n, a;
	cin >> n;
	while (n--) {
		cin >> a;
		arr[a + 100]++;
	}
	int s;
	cin >> s;
	cout << arr[s + 100];
	return 0;
}