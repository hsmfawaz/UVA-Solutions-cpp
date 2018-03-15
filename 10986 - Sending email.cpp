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
const int oo = 20001, OO = 10e8;
struct edge {
	int from, to, weight;
	bool del;
	edge(int f, int t, int c, bool d = false) {
		from = f, to = t, weight = c;
		del = d;
	}
	bool operator <(const edge &e) const {
		return weight > e.weight;
	}

};
int n, m, nn, mm, c, src, dest;
vector<edge> edges[oo];
int Dijkstra2() // O(E logV)
{
	vi dist(n, OO), prev(n, -1);
	dist[src] = 0;

	priority_queue<edge> q;
	q.push(edge(-1, src, 0));

	while (!q.empty()) {
		edge e = q.top();
		q.pop();

		if (e.weight > dist[e.to])
			continue;   // some other state reached better

		prev[e.to] = e.from;

		rep(j, 0, sz(edges[e.to]))
		{
			edge ne = edges[e.to][j];
			if (dist[ne.to] > dist[ne.from] + ne.weight) {
				ne.weight = dist[ne.to] = dist[ne.from] + ne.weight;
				q.push(ne);
			}
		}
	}

	return dist[dest];
}

void solution() {
	int t;
	cin >> t;
	rep(tt,0,t)
	{
		cin >> n >> m >> src >> dest;
		clr(edges, 0);
		rep(i,0,m)
		{
			cin >> nn >> mm >> c;
			edges[nn].pb(edge(nn, mm, c)), edges[mm].pb(edge(mm, nn, c));
		}
		int dj = Dijkstra2();
		cout << "Case #" << tt + 1 << ": ";
		if (dj == OO)
			cout << "unreachable\n";
		else
			cout << dj << endl;

	}
}
int main() {
	FastIO;
	solution();
	return 0;
}
