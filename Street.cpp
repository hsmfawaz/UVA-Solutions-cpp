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
const int MAX = 10001;
int G[MAX][MAX], V[MAX], L[MAX], n, m, gpe, c, t, tt;
void dfs(int u, int v) {
	V[v] = L[v] = ++gpe;
	for (int i = 1; i <= n; i++) {
		if (G[v][i]) {
			if (!V[i]) {
				dfs(v, i);
				L[v] = min(L[v], L[i]);
				if (L[i] <= V[v]) {
					G[i][v] = 0;
				}
			} else if (i != u) {
				L[v] = min(L[v], V[i]);
				G[i][v] = 0;
			}
		}
	}
}
void solution() {
	while (cin >> n >> m, n) {
		c++;
		clr(G, 0), clr(V, 0), clr(L, 0);
		rep(i,0,m)
			cin >> t >> tt, G[t][tt] = G[tt][t] = 1;

		rep(i,1,n+1)
			if (!V[i])
				dfs(i, i);

		cout << c << "\n\n";
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (G[i][j])
					cout << i << " " << j << endl;
		cout << "#" << endl;
	}
}
int main() {
	FastIO;
	solution();
	return 0;
}
