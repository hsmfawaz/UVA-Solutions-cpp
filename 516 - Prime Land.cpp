#include <bits/stdc++.h>
using namespace std;
#define sz(a) int((a).size())
#define all(c) (c).begin(),(c).end()
typedef long long ll;
const int oo = 32770;
bool prime[oo];
vector<int> primes;
void sieve() {
	prime[0] = prime[1] = 0;
	for (int i = 2; i * i <= oo; i++) {
		if (prime[i]) {
			for (int j = 2 * i; j < oo; j += i)
				prime[j] = 0;
		}
	}
	for (int i = 0; i < oo; ++i)
	{
		if (prime[i])
			primes.push_back(i);
	}
}
int main() {
	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	memset(prime, 1, sizeof prime);
	sieve();
	string c;
	while (getline(cin, c), c != "0") {
		int x = 1, n, m, ct = 1;
		stringstream st(c);
		while (st >> n >> m)
			x *= pow(n, m);
		x--;
		map<int, int> mp;
		for (auto p : primes) {
			while (x % p == 0) {
				x /= p;
				mp[p]++;
			}
		}
		for (map<int, int>::reverse_iterator i = mp.rbegin(); i != mp.rend(); ++i, ct++)
		{
			cout << i->first <<  " " << i->second << (sz(mp) != ct ? " " : "") ;
		}
		cout << endl;
	}
	return 0;
}