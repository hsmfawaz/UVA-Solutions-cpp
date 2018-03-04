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
vector<vi> p;
bool vis[101];
vi topo;
void dfs(int pos) {
	vis[pos] = true;
	rep(i,0,sz(p[pos]))
		if (!vis[p[pos][i]])
			dfs(p[pos][i]);
	topo.pb(pos);
}
void solution() {
	int n, m;
	while (cin >> n >> m, n) {
		p.resize(n + 1);
		p.clear(), clr(vis), topo.clear();
		rep(i,0,m)
		{
			int t1, t2;
			cin >> t1 >> t2;
			p[t1].pb(t2);
		}
		rep(i,1,n+1)
			if (!vis[i])
				dfs(i);
		for (int i = sz(topo) - 1; i >= 0; i--)
			cout << topo[i] << (i != 0 ? " " : "");
		cout << endl;
	}
}
int main() {
//	FastIO;
	solution();
	return 0;
}
