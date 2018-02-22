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
const int oo = (int) 10e5;
void solution() {
	int t, n, x[1001], sm;
	cin >> t;
	rep(tt,0,t)
	{
		cin >> n;
		rep(i,0,n)
			cin >> x[i];
		sm = 0;
		rep(i,1,n)
			rep(w,0,i)
				if (x[w] <= x[i])
					sm++;
		cout << sm << endl;
	}
}
int main() {
	FastIO;
	solution();
	return 0;
}
