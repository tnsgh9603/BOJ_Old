#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int n;
	cin >> n;
	bitset<100001> v;
	while (n--) {
		int a, b;
		cin >> a >> b;
		for (int i = a; i < b; i++) {
			v[i] = 1;
		}
	}
	cout << v.count();
	return 0;
}
/*
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
#define X first
#define Y second
typedef long long ll;
typedef pair<ll, ll> pii;
const ll INF = ll(1e9) + 7;
int main() {
   fastio;
   ll n;
   cin >> n;
   vector<pii> v(n);
   for (ll i = 0; i < n; i++) cin >> v[i].X >> v[i].Y;
   sort(v.begin(), v.end(), [&](pii a, pii b) {
	  if (a.X != b.X) {
		return a.X < b.X;
	  }
	  return a.Y > b.Y;
   });
   ll ans = 0;
   for (ll i = 0, prev = -INF; i < n; i++) {
	  if (v[i].Y < prev) {
		continue;
	  }
	  if (prev < v[i].X) {
		prev = v[i].X;
	  }
	  ans += v[i].Y - prev;
	  prev = v[i].Y;
   }
   cout << ans;
   return 0;
}

*/