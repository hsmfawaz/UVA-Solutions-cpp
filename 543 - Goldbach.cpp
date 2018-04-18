#include <bits/stdc++.h>
using namespace std;
#define sz(a) int((a).size())
#define all(c) (c).begin(),(c).end()
typedef long long ll;
const int oo = 10e6 + 1;
bool prime[oo];
vector<int> p;
void sieve(int n) {
	prime[0] = prime[1] = 0;
	for (int i = 2; i * i <= n; ++i)
	{
		if (prime[i])
			for (int j = i * 2; j <= n; j += i)
				prime[j] = 0;
	}
	for (int i = 0, ct = 0; i < n; ++i)
	{
		if (prime[i])
			p.push_back(i), ct++;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	memset(prime, 1, sizeof prime);
	sieve(oo);
	int n;
	while (cin >> n, n) {
		for (int i = 0; i < sz(p) and p[i] <= n; ++i)
		{
			if (prime[n - p[i]]) {
				cout << n << " = " <<  p[i] << " + " << n - p[i] << endl;
				break;
			}
		}
	}
	return 0;
}