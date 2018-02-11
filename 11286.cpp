#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define sz(a) int((a).size())
#define sza(a) (int)(sizeof(a)/sizeof((a)[0]))
#define all(c) (c).begin(),(c).end()
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define clr(x) memset(x,0,sizeof x)
#define pb push_back
#define fi first
#define sec second
typedef vector<int> vi;
typedef long long ll;
const int MX = 10e8 + 1;
int ct[500], qq[10001];
void Solution() {
	int x, t;
	while (cin >> x,x) {
		clr(ct),clr(qq);
		map<set<int>, int> xv;
		rep(i,0,x)
		{
			set<int> av;
			rep(j,0,5)
			{
				cin >> t;
				av.insert(t);
			}
			xv[av]++;

		}
		int i = 0;
		for (auto it : xv) {
			qq[i] += it.second;
			i++;
		}
		sort(qq, qq + 10001, greater<int>());
		int ct = qq[0], cf = 0;
		rep(j,0,10001)
		{
			if (qq[j] == ct)
				cf += qq[j];
			else
				break;
		}
		cout << cf<<endl;
	}
}
int main() {
	FastIO;
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
//	freopen("output.in", "w", stdout);
#endif
	Solution();
	return 0;
}
