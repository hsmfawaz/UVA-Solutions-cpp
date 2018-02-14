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
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long ul;
const int MX = 10e5 + 1;
void Solution() {
	int x, y;
	while (cin >> x >> y, x) {
		vi dragon(x), knight(y);
		rep(i,0,x)
			cin >> dragon[i];
		rep(i,0,y)
			cin >> knight[i];
		if (x > y)
			cout << "Loowater is doomed!\n";
		else {
			int ct = 0;
			sort(all(dragon));
			sort(all(knight));
			bool fal = true;
			rep(i,0,x)
			{
				vi::iterator ib = lower_bound(knight.begin(), knight.end(),
						dragon[i]);
				if (dragon[i] <= *ib and ib != knight.end()) {
					ct += *ib;
					knight.erase(ib);
				}

				else {
					fal = false;
					break;
				}

			}
			if (fal)
				cout << ct << endl;
			else
				cout << "Loowater is doomed!\n";
		}
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
