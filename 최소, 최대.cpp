#include <iostream>
using namespace std;
int main() {
	int a, b, max, min;
	cin >> a;
	for (int i = 1; i <= a; i++) {
		cin >> b;
		if (i==1){
			max = b;
			min = b;
		}
		if (max < b) {
			max = b;
		}
		if (min > b) {
			min = b;
		}
	}
	cout << min << " " << max;
	return 0;
}