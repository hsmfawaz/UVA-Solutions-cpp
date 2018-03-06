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
int rets = 0;
int dfs(int node) {
	int m = -1, m1 = -1, m2 = -1;
	vis[node] = true;
	for (int it : g[node]) {
		if (!vis[it]) {
			m = dfs(it);
			if (m >= m1)
				m2 = m1, m1 = m;
			else if (m > m2)
				m2 = m;
		}
	}

	rets = max(rets, ++m1 + ++m2);
	return m1;
}
void solution() {
	int n, t, x;
	cin >> n;
	g.resize(n);
	rep(i,0,n-1)
		cin >> t >> x, g[t].pb(x), g[x].pb(t);
	dfs(1);
	cout << rets;

}
int main() {
	FastIO;
	solution();
	return 0;
}
