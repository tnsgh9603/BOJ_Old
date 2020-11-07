#include <iostream>
using namespace std;
int main() {
	int input, country, airplane, start, stop;
	cin >> input;
	for (int i = 1; i <= input; i++) {
		cin >> country >> airplane;
		for (int k = 1; k <= airplane; k++) {
			cin >> start >> stop;
		}
		cout << country - 1 << "\n";
	}
	return 0;
}
/*int arr[1001][1001] = { 0, };
int main() {
	int input, country, airplane, start, stop;
	cin >> input;
	for (int i = 1; i <= input; i++) {
		cin >> country >> airplane;
		for (int k = 1; k <= airplane; k++) {
			cin >> start >> stop;
			arr[start][stop]++;
			arr[stop][start]++;
		}
		for (int q = 2; q <= 1000; q++) {
			for (int w = 2; w <= 1000; w++) {
				if (arr[q][w] != 0) {

				}
			}
		}
	}
	return 0;
}*/