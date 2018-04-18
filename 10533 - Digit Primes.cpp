#include <bits/stdc++.h>
using namespace std;
#define sz(a) int((a).size())
#define all(c) (c).begin(),(c).end()
typedef long long ll;
const int oo = 10e6 + 2;
bool prime[oo];
int res[oo];
bool primedigit(int n) {
	int sum = 0;
	while (n) {
		sum += (n % 10);
		n /= 10;
	}
	return prime[sum];
}
void sieve() {
	prime[0] = prime[1] = 0;
	for (int i = 2; i * i < oo; ++i)
	{
		if (prime[i])
			for (int j = i * 2; j < oo; j += i)
				prime[j] = 0;
	}
	int ct = 0;
	for (int i = 0; i < oo; ++i)
	{
		if (prime[i] and primedigit(i))
			ct++;
		res[i] = ct;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string x, y;
	int n;
	scanf("%d", &n);
	memset(prime, 1, sizeof prime);
	sieve();

	while (n--) {
		int x, y;
		scanf("%d %d", &x, &y);
		printf("%d\n", res[y] - res[x-1]);
	}
	return 0;
}