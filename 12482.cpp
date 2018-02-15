#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define sz(a) int((a).size())
#define sza(a) (int)(sizeof(a)/sizeof((a)[0]))
#define all(c) (c).begin(),(c).end()
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define clr(x) memset(x,0,sizeof x)
#define ft first
#define sd second
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long ul;
const int MX = 10e5 + 1;

void Solution() {
	int n, l, c;
	while (cin >> n >> l >> c) {
		int ct = 1, xa[n];
		string s;
		rep(i,0,n)
			cin >> s, xa[i] = sz(s);

		for (int i = 0, e = 0; i < n; i++)
			if (e + xa[i] <= c)
				e += ++xa[i];
			else
				e = ++xa[i], ct++;

		cout << ct / l + (ct % l > 0) << endl;
	}
}
int main() {
	FastIO;
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
//	freopen("output.in", "w", stdout);
#endif
	Solution();
	return 0;
}
