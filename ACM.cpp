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
	int from, to, weight, index;
	bool del;
	edge(int f, int t, int c, int idx, bool d = false) {
		from = f, to = t, weight = c, index = idx;
		del = d;
	}
	bool operator <(const edge &e) const {
		return weight > e.weight;
	}
	bool operator ==(const edge & e) const {
		return (from == e.from && to == e.to && weight == e.weight);
	}
};
struct UnionFind {
	vector<int> rank, parent;
	vector<edge> edges;
	int number;
	UnionFind(int n) {
		number = n;
		rank = vector<int>(number), parent = vector<int>(number);
		for (int i = 0; i < number; i++)
			parent[i] = i, rank[i] = 1;
	}
	void clear() {
		rank = vector<int>(number), parent = vector<int>(number);
		for (int i = 0; i < number; i++)
			parent[i] = i, rank[i] = 1;
	}
	void addEdge(int x, int y, int cost, int index) {
		edges.pb(edge(x, y, cost, index));
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

	pair<vector<edge>, int> Kruskal() {
		priority_queue<edge> q;
		for (edge it : edges)
			if (!it.del)
				q.push(it);
		vector<edge> taken;
		int maxweight = 0;
		while (!q.empty()) {
			edge e = q.top();
			q.pop();
			if (union_sets(e.from, e.to))
				maxweight += e.weight, taken.pb(e);
		}
		if (sz(taken) != number - 1)
			return {vector<edge>(),INT_MAX};
		return {taken,maxweight};
	}
};
int t, n, m, nn, mm, c;
void solution() {
	cin >> t;
	rep(tt,0,t)
	{
		cin >> n >> m;
		UnionFind uf(n);
		rep(i,0,m)
		{
			cin >> nn >> mm >> c, nn--, mm--;
			uf.edges.pb(edge(nn, mm, c, i));
		}

		pair<vector<edge>, int> ret = uf.Kruskal();
		int ScMst = INT_MAX, firstone = ret.sd;
		rep(i,0,sz(ret.ft))
		{
			uf.clear();
			uf.edges[ret.ft[i].index].del = true;
			pair<vector<edge>, int> ret2 = uf.Kruskal();
			uf.edges[ret.ft[i].index].del = false;

			ScMst = min(ScMst, ret2.sd);

		}
		cout << firstone << " " << ScMst << endl;
	}
}
int main() {
	FastIO;
	solution();
	return 0;
}
