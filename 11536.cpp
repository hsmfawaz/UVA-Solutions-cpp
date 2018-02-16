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
typedef unsigned long long ll;
typedef unsigned long ul;
const int MX = 1000001;
int seq[MX], vis[MX];
void Solution() {
	int t;
	cin >> t;
	rep(tt,1,t+1)
	{
		clr(seq), clr(vis);
		cout << "Case " << tt << ": ";
		int n, m, k;
		cin >> n >> m >> k;

		seq[1] = 1, seq[2] = 2, seq[3] = 3;

		rep(i,4,n+1)
			seq[i] = (seq[i - 1] + seq[i - 2] + seq[i - 3]) % m + 1;

		int a = 1, b = 1, c = 0;
		int res = n + 1;
		while (a <= n) {
			int t = seq[a++];
			vis[t]++;
			if (t <= k && vis[t] == 1)
				c++;

			while (b < a && c == k) {
				res = min(res, a - b);
				t = seq[b++];
				vis[t]--;
				if (t <= k && vis[t] == 0)
					c--;
			}
		}

		if (res <= n)
			cout << res << endl;
		else
			cout << "sequence nai\n";
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
