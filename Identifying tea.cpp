#include <iostream>
using namespace std;
int arr[5];
int main() {
	int a, b;
	cin >> a;
	for (int i = 0; i < 5; i++) {
		cin >> b;
		arr[b]++;
	}
	cout << arr[a];
}