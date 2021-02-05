#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() { 
	fastio;
	int P;
	cin >> P;
	for (int i = 0; i < P; i++) {
		int N;
		double D, A, B, F, time = 0.0;
		cin >> N >> D >> A >> B >> F;
		time = D / (A + B);
		cout << N << ' ' << F * time << '\n';
	}
	return 0;
}