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
const int oo = 101;
struct edge {
	int from, to, weight;
	edge(int f, int t, int c) {
		from = f, to = t, weight = c;
	}
	bool operator <(const edge &e) const {
		return weight > e.weight;
	}
};
struct UnionFind {
	vector<int> rank, parent;
	vector<edge> edges;
	int number;
	UnionFind(int n) {
		number = n;
		rank = vector<int>(n), parent = vector<int>(n);
		for (int i = 0; i < n; i++)
			parent[i] = i, rank[i] = 1;
	}
	void addEdge(int x, int y, int cost) {
		edges.pb(edge(x, y, cost));
	}
	int find_set(int x) {
		if (x == parent[x])
			return x;
		return parent[x] = find_set(parent[x]);
	}

	bool same_set(int x, int y) {
		return find_set(x) == find_set(y);
	}

	void link(int x, int y) {
		if (rank[x] > rank[y])
			swap(x, y);
		parent[x] = y;
		if (rank[x] == rank[y])
			rank[y]++;
	}

	bool union_sets(int x, int y) {
		x = find_set(x), y = find_set(y);
		if (x != y) {
			link(x, y);
		}
		return x != y;
	}

	vi Kruskal() {
		priority_queue<edge> q;
		for (edge it : edges)
			q.push(it);
		vector<int> ret;
		while (!q.empty()) {
			edge e = q.top();
			q.pop();
			if (union_sets(e.from, e.to)) {
				ret.pb(e.weight);
			}
		}
		return ret;
	}

};
int t, n, m;
pair<int, int> cord[505];
int Dist(int i, int j) {
	int x = cord[i].ft - cord[j].ft, y = cord[i].sd - cord[j].sd;
	return x * x + y * y;
}
void solution() {
	cin >> t;
	rep(tt,0,t)
	{
		cin >> n >> m;
		UnionFind uf(m);
		map<ii, int> mp;
		int id = -1;
		rep(i,0,m)
		{
			cin >> cord[i].ft >> cord[i].sd;
			if (!mp[cord[i]])
				mp[cord[i]] = ++id;
			rep(j,0,i)
				uf.addEdge(mp[cord[i]], mp[cord[j]], Dist(i, j));
		}

		vi ret = uf.Kruskal();
		sort(all(ret),greater<int>());
		cout << fixed << setprecision(2) << sqrt(ret[n-1]) << endl;
	}
}
int main() {
	FastIO;
	solution();
	return 0;
}
