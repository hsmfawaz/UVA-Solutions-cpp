#include <bits/stdc++.h>
using namespace std;
#define sz(a) int((a).size())
#define all(c) (c).begin(),(c).end()
typedef long long ll;
const int oo = INT_MAX;
bool prime[2001];
int arr[1000];
void sieve(int n) {
	prime[0] = prime[1] = 0;
	for (int i = 2; i * i <= n; ++i)
	{
		if (prime[i])
			for (int j = i * 2; j <= n; j += i)
				prime[j] = 0;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	memset(prime, 1, sizeof prime);
	sieve(2001);
	cin >> n;
	for (int t = 1; t <= n; ++t)
	{
		memset(arr, 0, sizeof arr);
		string s;
		cin >> s;
		for (char c : s)
			arr[(int)c]++;
		int ct = 0;
		cout << "Case " << t<< ": ";
		for (int i = 0; i < 200; ++i)
		{
			if (prime[arr[i]])
				cout << (char)i, ct++;

		}
		if (ct == 0)
			cout << "empty";
		cout << endl;
	}
	return 0;
}