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
const int oo = 10e3 + 1;
vector<vi> g(oo);
bool vis[oo];

pair<int, int> dfs(int node, int parent) {
	int diam = 0;
	int mxheights[3];
	clr(mxheights, -1);

	for (int it : g[node]) {
		if (it != parent) {
			pair<int, int> p = dfs(it, node);
			diam = max(diam, p.ft);

			mxheights[0] = p.sd + 1;
			sort(mxheights, mxheights + 3);
		}
	}
	rep(i,0,3)
		mxheights[i] += mxheights[i] == -1 ? 1 : 0;

	diam = max(diam, mxheights[1] + mxheights[2]);
	return {diam,mxheights[2]};
}
void solution() {
	int n, t, x;
	cin >> n;
	g.resize(n);
	rep(i,0,n-1)
		cin >> t >> x, g[t].pb(x), g[x].pb(t);
	cout << dfs(1, 0).ft;

}
int main() {
	FastIO;
	solution();
	return 0;
}
