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
const int oo = 10000, OO = 10e8;
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
int n, m, c, src, dest;
int R[11];
int Dijkstra() {
	vi dist(oo, OO);
	dist[src] = 1;

	queue<int> q;
	q.push(src);

	while (!q.empty() and dist[dest] == OO) {
		int e = q.front();
		q.pop();

		rep(i,0,n)
		{
			int tmp = (e + R[i]) % 10000;
			if (dist[tmp] == OO) {
				dist[tmp] = dist[e] + 1;
				q.push(tmp);
			}
		}

	}

	return dist[dest];
}

void solution() {
	int tt = 1;
	while (cin >> src >> dest >> n, n | m) {
		rep(i,0,n)
			cin >> R[i];
		int dj = Dijkstra();
		cout << "Case " << tt++ << ": ";
		if (dj == OO)
			cout << "Permanently Locked\n";
		else
			cout << dj - 1 << endl;
	}
}
int main() {
	FastIO;
	solution();
	return 0;
}
