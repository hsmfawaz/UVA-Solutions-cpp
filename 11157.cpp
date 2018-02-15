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
int stone[200];
bool small[200];
void Solution() {
	int t;
	cin >> t;
	rep(tt,0,t)
	{
		int n, m, w;
		cin >> n >> m;
		vi xa;
		rep(i,0,n)
		{
			char c, s;
			cin >> c >> s >> stone[i];
			small[i] = c != 'B';
		}
		stone[n] = m, small[n] = 0, n++;
		int A, B, res;
		A = B = res = 0;
		rep(i,0,n)
		{
			if (!small[i]) {
				res = max(res, stone[i] - min(A, B));
				A = B = stone[i];
			} else {
				if (A <= B) {
					res = max(res, stone[i] - A);
					A = stone[i];
				} else {
					res = max(res, stone[i] - B);
					B = stone[i];
				}
			}
		}
		printf("Case %d: %d\n", tt + 1, res);
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
