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
typedef pair<int, int> ii;
typedef vector<ii> vii;
#define rep(i,a,n) for (ll i=(a);i<(n);i++)
typedef unsigned long ul;
const int oo = 501, OO = 10e8;
int t, n, m, g[oo][oo], tt, ttt, dep[oo];
void solution() {
	cin >> t;
	int rank[oo];
	while (t--) {
		cin >> n;
		rep(i,0,n)
			cin >> rank[i];
		clr(g, 0);
		rep(i,0,n)
			rep(j,i+1,n)
				g[rank[i]][rank[j]] = 1;
		cin >> m;
		while (m--) {
			cin >> tt >> ttt;
			swap(g[tt][ttt], g[ttt][tt]);
		}

		rep(i,1,n+1)
		{
			dep[i] = 0;
			rep(j,1,n+1)
				dep[i] += g[j][i];
		}
		queue<int> q;
		rep(i,1,n+1)
			if (dep[i] == 0)
				q.push(i);
		int cur, id = 0, topo[n + 1];

		while (!q.empty()) {
			cur = q.front();
			topo[id++] = cur;
			q.pop();
			rep(i,1,n+1)
				if (g[cur][i])
					if (--dep[i] == 0)
						q.push(i);
		}

		if (id != n)
			cout << "IMPOSSIBLE\n";
		else
			rep(i,0,n)
				cout << topo[i] << (i == n - 1 ? "\n" : " ");
	}
}
int main() {
	FastIO;
	solution();
	return 0;
}
