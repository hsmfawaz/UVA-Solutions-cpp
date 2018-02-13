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
	int n;
	cin >> n;
	rep(t,0,n)
	{
		int x, y, z, mx = 0, eggs = 0;
		cin >> x >> y >> z;
		int na[x];
		rep(i,0,x)
			cin >> na[i];
		sort(na, na + x);
		int i = 0;
		while (mx + na[i] <= z and eggs + 1 <= y and i < x)
			mx += na[i], eggs++,i++;

		cout << "Case " << t + 1 << ": " << eggs << endl;
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
