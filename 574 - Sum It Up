#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define sz(a) int((a).size())
#define sza(a) (int)(sizeof(a)/sizeof((a)[0]))
#define all(c) (c).begin(),(c).end()
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define clr(x) memset(x,0,sizeof x)
#define ft first
#define sd second
#define pb push_back
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long ul;
const int oo = 21;
bool vis[13];
int x[13], t, n;
set<vi> st;
void run(int pos) {
	if (pos == n) {
		vi tt;
		int sm = 0;
		rep(i,0,n)
			if (vis[i])
				tt.pb(x[i]), sm += x[i];
		if (sm == t)
			st.insert(tt);
		return;
	}

	vis[pos] = true;
	run(pos + 1);
	vis[pos] = false;
	run(pos + 1);
}
void solution() {
	while (cin >> t >> n, t) {

		rep(i,0,n)
			cin >> x[i];
		sort(x, x + n, greater<int>());
		clr(vis);
		st.clear();
		run(0);
		printf("Sums of %d:\n", t);
		if (sz(st) > 0) {
			for (set<vi>::reverse_iterator it = st.rbegin(); it != st.rend();
					it++) {
				printf("%d", it->at(0));
				rep(i,1,(int)it->size())
					printf("+%d", it->at(i));
				printf("\n");
			}
		} else
			printf("NONE\n");
	}
}
int main() {
	FastIO;
	solution();
	return 0;
}
