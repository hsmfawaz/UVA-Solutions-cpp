#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define sz(a) int((a).size())
#define sza(a) (int)(sizeof(a)/sizeof((a)[0]))
#define all(c) (c).begin(),(c).end()
#define clr(x) memset(x,0,sizeof x)
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define ft first
#define sd second
#define ri reverse_iterator
#define pb push_back
typedef vector<int> vi;
typedef long long ll;
const int oo = 200;
int t, ct;
map<int, vi> g;
bool vis[oo];
void dfs(int pos) {
	if (vis[pos])
		return;
	vis[pos] = 1;
	rep(i,0,sz(g[pos]))
		dfs(g[pos][i]);
}
void solution() {
	scanf("%d\n\n", &t);
	string s;
	rep(tc,0,t)
	{
		g.clear(), clr(vis);
		getline(cin, s);
		rep(i,0,s[0] - 'A' + 1)
			g[i] = {};
		while (getline(cin, s), !s.empty())
			g[s[0] - 'A'].pb(s[1] - 'A'), g[s[1] - 'A'].pb(s[0] - 'A');
		ct = 0;
		for (auto it : g)
			if (!vis[it.ft])
				ct++, dfs(it.ft);
		if (tc != 0)
			printf("\n");
		printf("%d\n", ct);
	}
}
int main() {
//	FastIO;
	solution();
	return 0;
}
