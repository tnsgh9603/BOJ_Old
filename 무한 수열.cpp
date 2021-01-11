#include <iostream>
#include <map>
typedef long long ll;
using namespace std;
map <ll, ll> mp;
ll N, P, Q;
ll sol(ll r){
	if (mp.count(r)) {
		return mp[r];
	}
	return mp[r] = sol(r / P) + sol(r / Q);
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> P >> Q;
	mp.insert(pair<ll, ll>(0, 1));
	cout << sol(N);
	return 0;
}