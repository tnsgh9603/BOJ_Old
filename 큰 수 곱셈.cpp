#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//num[]의 자릿수를 올림을 처리한다.
void normalize(vector<int>& num)
{
	num.push_back(0);

	//자릿수 올림을 처리한다.
	int size = num.size();
	for (int i = 0; i < size - 1; i++)
	{
		if (num[i] < 0)
		{
			int borrow = (abs(num[i]) + 9) / 10;
			num[i + 1] -= borrow;
			num[i] += borrow * 10;
		}
		else
		{
			num[i + 1] += num[i] / 10;
			num[i] %= 10;
		}
	}
	//앞에 남은 0을 제거한다.
	while (num.size() > 1 && num.back() == 0)
		num.pop_back();
}

//초등학교식 정수 곱셈
vector<int> multiply(const vector<int>& a, const vector<int>& b)
{
	vector<int> c(a.size() + b.size() + 1, 0);

	int aSize = a.size();
	int bSize = b.size();

	for (int i = 0; i < aSize; i++)
		for (int j = 0; j < bSize; j++)
			c[i + j] += a[i] * b[j];
	normalize(c);
	return c;
}

//a += b * (10^k)
void addTo(vector<int>& a, const vector<int>& b, int k)
{
	int originalASize = a.size();
	if (a.size() < b.size() + k)
		a.resize(b.size() + k);
	a.push_back(0);

	int aSize = a.size();
	for (int i = originalASize; i < aSize; i++)
		a[i] = 0;

	int bSize = b.size();

	for (int i = 0; i < bSize; i++)
		a[i + k] += b[i];

	normalize(a);
}

// a -= b
// a>= b인 경우에만 사용 가능하다.
void subFrom(vector<int>& a, const vector<int>& b)
{
	int bSize = b.size();

	for (int i = 0; i < bSize; i++)
		a[i] -= b[i];
	normalize(a);
}

vector<int> karatsuba(const vector<int>& a, const vector<int>& b)
{
	int an = a.size(), bn = b.size();

	//a가 b보다 짧을 경우 둘을 바꾼다.
	if (an < bn)
		return karatsuba(b, a);
	//기저 사례 : a나 b가 비어있는 경우
	if (an == 0 || bn == 0)
		return vector<int>();
	//기저 사례 : a가 비교적 짧은 경우, O(n^2) 곱셈으로 변경한다.(성능을 위함)
	if (an <= 50)
		return multiply(a, b);
	int half = an / 2;

	vector<int> a0(a.begin(), a.begin() + half);
	vector<int> a1(a.begin() + half, a.end());
	vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
	vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());

	//z2 = a1 * b1
	vector<int> z2 = karatsuba(a1, b1);

	//z0 = a0 * b0
	vector<int> z0 = karatsuba(a0, b0);

	//z1 = ((a0 + a1) * (b0 + b1)) - z0 - z2
	addTo(a0, a1, 0);
	addTo(b0, b1, 0);
	vector<int> z1 = karatsuba(a0, b0);
	subFrom(z1, z0);
	subFrom(z1, z2);

	//병합 과정
	//ret = z0+z1*10^half + z2 * 10(half*2)
	vector<int> ret(z2.size() + half * 2, 0);
	addTo(ret, z0, 0);
	addTo(ret, z1, half);
	addTo(ret, z2, half * 2);
	return ret;
}

int main()
{
	vector<int> a;
	vector<int> b;
	for (int i = 0; i < 100; i++)
		a.push_back(i % 10);

	for (int i = 0; i < 73; i++)
		b.push_back(i % 10);
	vector<int> c = karatsuba(b, a);

	int cSize = c.size();
	for (int i = 0; i < cSize; i++)
		cout << c[i];

	return 0;
}
/*
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define MOD 1000000007 
#define INF 987654321 

const double PI = acos(-1);
typedef complex<double> cpx;

void FFT(vector<cpx> &f, cpx w){
	int n = f.size();
	if(n == 1) return;
	vector<cpx> even(n/2), odd(n/2);
	for(int i = 0; i < n; i++)
		(i % 2 ? odd : even)[i / 2] = f[i];
	FFT(even, w*w);
	FFT(odd, w*w);
	
	cpx wp(1,0);
	for(int i = 0; i < n / 2; i++){
		f[i] = even[i] + wp*odd[i];
		f[i + n / 2] = even[i] - wp* odd[i];
		wp *= w;
	}
}

vector<cpx> multiply(vector<cpx> a, vector<cpx> b){
	int n = 1;
	while(n < a.size() + 1 || n < b.size() + 1) n *= 2;
	n *= 2;
	a.resize(n);
	b.resize(n);
	vector<cpx> c(n);
	
	cpx w(cos(2*PI/n), sin(2*PI/n));
	FFT(a,w);
	FFT(b,w);
	for(int i = 0; i < n; i++)
		c[i] = a[i]*b[i];
	FFT(c, cpx(1,0)/w);
	for(int i = 0; i < n; i++){
		c[i] /= cpx(n, 0);
		c[i] = cpx(round(c[i].real()), round(c[i].imag()));
	}
	return c;
}


int main(){
	vector<cpx> x,y,z;
	while(1){
		char c = getchar();
		if(c == ' ') break;
		x.push_back(cpx(c-'0', 0));
	}
	while(1){
		char c = getchar();
		if(c == '\n' || c == EOF) break;
		y.push_back(cpx(c-'0', 0));
	}
	reverse(x.begin(), x.end());
	reverse(y.begin(), y.end());
	z = multiply(x, y);
	int len = z.size();
	int carry = 0;
	vector<int> ans;
	for(int i = 0; i < len; i++){
		int n = (int)round(z[i].real()) + carry;
		carry = n / 10;
		ans.push_back(n % 10);
	}
	while(carry > 0){
		ans.push_back(carry % 10);
		carry /= 10;
	}
	int i = ans.size() - 1;
	for(; i >= 0; i--){
		if(ans[i] != 0) break;
	}
	if(i < 0) puts("0");
	else{
		for(; i >= 0; i--){
			printf("%d",ans[i]);
		}
	}
	return 0;
}
*/