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
const int oo = 751, OO = 10e8;
struct edge {
	int from, to;
	double weight;
	bool del;
	edge(int f, int t, double c, bool d = false) {
		from = f, to = t, weight = c;
		del = d;
	}
	bool operator <(const edge &e) const {
		return weight > e.weight;
	}

};
struct UnionFind {
	vector<int> rank, parent;
	vector<edge> edges;
	int number;
	bool vis[oo][oo];
	UnionFind(int n) {
		number = n;
		rank = vector<int>(n), parent = vector<int>(n);
		for (int i = 0; i < n; i++)
			parent[i] = i, rank[i] = 1;
		clr(vis, 0);
	}
	void addEdge(int x, int y, double cost, bool ds = false) {
		edges.pb(edge(x, y, cost, ds));
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

	void Kruskal(int es) {
		if (es >= number - 1) {
			printf("No new highways need\n");
			return;
		}
		priority_queue<edge> q;
		for (edge it : edges)
			q.push(it);

		while (es < number - 1 and !q.empty()) {
			edge e = q.top();
			q.pop();
			if (union_sets(e.from, e.to)) {
				printf("%d %d\n", e.from + 1, e.to + 1);
				es++;
			}
		}
	}

};

int n, m;
pair<int, int> cord[oo];
double Dist(int i, int j) {
	int x = cord[i].ft - cord[j].ft, y = cord[i].sd - cord[j].sd;
	return sqrt(x * x + y * y);
}
bool cmp(edge a, edge b) {
	return a.from < b.from;
}
void solution() {
	int t;
	scanf("%d", &t);
	while (t--) {
		clr(cord, 0);
		scanf("%d", &n);
		int x, y;
		UnionFind uf(n);
		rep(i,0,n)
			scanf("%d %d", &cord[i].ft, &cord[i].sd);
		scanf("%d", &m);
		int is = 0;

		rep(i,0,m)
		{
			scanf("%d %d", &x, &y), x--, y--;
			if (uf.union_sets(x, y))
				is++;
			uf.vis[x][y] = uf.vis[y][x] = 1;

		}
		rep(i,0,n)
			rep(j,i+1,n)
				if (!uf.vis[i][j])
					uf.addEdge(i, j, Dist(i, j));

		uf.Kruskal(is);
		if (t)
			printf("\n");
	}
}
int main() {
	FastIO;
	solution();
	return 0;
}
