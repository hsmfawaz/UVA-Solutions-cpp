#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define sz(a) int((a).size())
#define sza(a) (int)(sizeof(a)/sizeof((a)[0]))
#define all(c) (c).begin(),(c).end()
#define clr(x) memset(x,0,sizeof x)
#define ft first
#define sd second
#define ri reverse_iterator
#define pb push_back
typedef vector<int> vi;
typedef long long ll;
#define rep(i,a,n) for (ll i=(a);i<(n);i++)
typedef unsigned long ul;
const int oo = 105;
vi adj[oo], ret;
bool vis[oo];
int n, m, tmp, mm, st;
void dfs(int i) {
	rep(j,0,sz(adj[i]))
		if (!vis[adj[i][j]])
			vis[adj[i][j]] = true, dfs(adj[i][j]);
}
void solution() {
	while (cin >> n, n) {
		clr(adj);
		while (cin >> m, m)
			while (cin >> tmp, tmp)
				adj[m].pb(tmp);
		cin >> mm;
		while (mm--) {
			clr(vis), ret.clear();
			cin >> st, dfs(st);
			rep(i,1,n+1)
				if (!vis[i])
					ret.pb(i);
			printf("%d", sz(ret));
			rep(i,0,sz(ret))
				printf(" %d", ret[i]);
			printf("\n");
		}
	}
}
int main() {
	FastIO;
	solution();
	return 0;
}
