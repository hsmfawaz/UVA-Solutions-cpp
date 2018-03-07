#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define sz(a) int((a).size())
#define sza(a) (int)(sizeof(a)/sizeof((a)[0]))
#define all(c) (c).begin(),(c).end()
#define clr(x,y) memset(x,(y),sizeof x)
#define ft first
#define sd second
#define ri reverse_iterator
#define pb push_back
typedef vector<int> vi;
typedef long long ll;
#define rep(i,a,n) for (ll i=(a);i<(n);i++)
typedef unsigned long ul;
const int oo = 10e6;
int n, m, a, b;
vi g[oo];
int vis[oo], flag = 0;
vi topo;
void dfs(int node) {
	vis[node] = 1;
	for (int i : g[node])
		if (vis[i] == 0)
			dfs(i);
		else if (vis[i] == 1) {
			flag = 1;
			return;
		}
	topo.pb(node);
	vis[node] = 2;
}
void solution() {
	while (cin >> n >> m, n) {
		clr(vis, 0), topo.clear(), flag = 0, clr(g, 0);

		rep(i,0,m)
			cin >> a >> b, g[a].pb(b);
		for (int i = 1; i <= n and !flag; i++)
			if (vis[i] == 0)
				dfs(i);

		if (flag)
			cout << "IMPOSSIBLE\n";
		else
			for (int i = sz(topo) - 1; i >= 0; i--)
				cout << topo[i] << endl;
	}
}
int main() {
	FastIO;
	solution();
	return 0;
}
