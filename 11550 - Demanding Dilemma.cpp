#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define sz(a) int((a).size())
#define sza(a) (int)(sizeof(a)/sizeof((a)[0]))
#define all(c) (c).begin(),(c).end()
#define clr(x) memset(x,0,sizeof x)
#define ft first
#define sd second
#define ri reverse_iterator
#define pb push_back
typedef vector<int> vi;
typedef long long ll;
#define rep(i,a,n) for (ll i=(a);i<(n);i++)
typedef unsigned long ul;
const int oo = 10001;
int t, n, m, b;
void solution() {
	cin >> t;
	while (t--) {
		cin >> n >> m;
		bool inc[n][m], f = true;
		clr(inc);
		rep(i,0,n)
			rep(j,0,m)
				cin >> inc[i][j];

		set<pair<int, int> > st;
		int pairs[2];
		for (int j = 0; j < m and f; j++) {
			int ct = 0;
			rep(i,0,n)
			{
				if (inc[i][j]) {
					ct++;
					if (ct > 2) {
						f = false;
						break;
					}
					pairs[ct - 1] = i;
				}
				if (ct == 2)
					st.insert( { pairs[0], pairs[1] });
			}

		}
		f = sz(st) != m ? false : f;
		cout << (f ? "Yes" : "No") << endl;
	}
}
int main() {
	FastIO;
	solution();
	return 0;
}
