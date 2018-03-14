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
const int oo = 10001;
int n, low[oo], seen[oo], ct;
vi g[oo];
set<pair<int, int> > res;
void dfs(int node, int parent) {
	low[node] = seen[node] = ++ct;
	for (int i : g[node]) {
		if (i == parent)
			continue;

		if (seen[i] == 0) {
			dfs(i, node);
			low[node] = min(low[node], low[i]);
			if (low[i] == seen[i]) {
				res.insert( { min(node, i), max(node, i) });
			}
		} else
			low[node] = min(low[node], seen[i]);
	}

}
void solution() {
	while (cin >> n) {
		clr(seen, 0), clr(low, 0), res.clear(), clr(g, 0);
		ct = 0;
		rep(i,0,n)
		{
			int x, y, z;
			scanf("%d (%d)", &x, &y);
			rep(j,0,y)
				cin >> z, g[x].pb(z);
		}

		rep(i,0,n)
			if (seen[i] == 0)
				dfs(i, -1);

		cout << sz(res) << " critical links\n";

		for (auto it : res)
			cout << it.ft << " - " << it.sd << endl;
		cout << endl;
	}

}
int main() {
//	FastIO;
	solution();
	return 0;
}
