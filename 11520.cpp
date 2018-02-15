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
int t, n;

bool safe(int a, int b) {
	return a >= 0 and a < n and b >= 0 and b < n;
}

void Solution() {
	cin >> t;
	rep(tt,1,t+1)
	{
		cin >> n;
		char g[n][n];
		rep(i,0,n)
			rep(j,0,n)
				cin >> g[i][j];

		rep(i,0,n)
		{
			rep(j,0,n)
			{
				char &cur = g[i][j];
				if (cur == '.') {
					vector<char> xs;
					if (safe(i, j + 1))
						xs.push_back(g[i][j + 1]);
					if (safe(i, j - 1))
						xs.push_back(g[i][j - 1]);
					if (safe(i + 1, j))
						xs.push_back(g[i + 1][j]);
					if (safe(i - 1, j))
						xs.push_back(g[i - 1][j]);
					string xa = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
					rep(z,0,sz(xs))
					{
						auto it = xa.find(xs[z]);
						if (it != string::npos)
							xa.erase(it, 1);
					}

					cur = xa.front();
				}
			}
		}

		cout << "Case " << tt << ":\n";
		rep(i,0,n)
		{
			rep(j,0,n)
				cout << g[i][j];
			cout << endl;
		}

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
