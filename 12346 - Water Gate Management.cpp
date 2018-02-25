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
#define pb push_back
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long ul;
const int oo = 21;
int n, g[oo], p[oo], m, tt, t, res = INT_MAX;
bool vis[oo];
void run(int pos) {
	if (pos == n) {
		int sum = 0, cult = 0;
		rep(i,0,n)
			if (vis[i])
				sum += p[i], cult += g[i] * m;
		if (cult >= tt)
			res = min(sum, res);
		return;
	}

	vis[pos] = true;
	run(pos + 1);
	vis[pos] = false;
	run(pos + 1);

}
void solution() {
	cin >> n;
	rep(i,0,n)
		cin >> g[i] >> p[i];
	cin >> t;
	t++;
	rep(i,1,t)
	{
		clr(vis);
		res = INT_MAX;
		cin >> tt >> m;
		run(0);
		if (res == INT_MAX)
			printf("Case %d: IMPOSSIBLE\n", i);
		else
			printf("Case %d: %d\n", i, res);
	}
}
int main() {
	FastIO;
	solution();
	return 0;
}
