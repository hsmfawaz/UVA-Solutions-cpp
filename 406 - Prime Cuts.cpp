#include <bits/stdc++.h>
using namespace std;
#define sz(a) int((a).size())
#define all(c) (c).begin(),(c).end()
typedef long long ll;
const int oo = INT_MAX;
bool prime[2000];
vector<int> p;
void sieve(int n) {
	prime[0] = 0;
	prime[1] = 1;
	for (int i = 2; i * i <= n; ++i)
	{
		if (prime[i])
			for (int j = i * 2; j <= n; j += i)
				prime[j] = 0;
	}
	for (int i = 1; i < n; ++i)
		if (prime[i])
			p.push_back(i);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, c;
	memset(prime, 1, sizeof prime);
	sieve(1001);
	while (cin >> n >> c) {
		cout << n << " " << c << ": ";
		vector<int> x;
		for (int i = 0; i < sz(p); ++i)
		{
			if (p[i] <= n)
				x.push_back(p[i]);
		}
		c = (sz(x) & 1 ? c * 2 - 1  : c * 2);
		c = min(c, sz(x));
		for (int i = (sz(x) / 2) - (c / 2); c ; ++i, c--)
		{
			cout << p[i] << (c - 1 == 0 ? "" : " " );
		}
		cout << endl << endl;
	}
	return 0;
}