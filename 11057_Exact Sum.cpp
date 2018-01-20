#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define sz(a) int((a).size())
#define sza(a) (int)(sizeof(a)/sizeof((a)[0]))
#define all(c) (c).begin(),(c).end()
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define clr(x) memset(x,0,sizeof x)
#define ginp(arr,len) rep(e,0,(len)) cin >> (arr)[e]
typedef vector<int> vi;
typedef unsigned long long ll;
#define ul unsigned long
const int MX = 10e5 + 1;
int n, m;
int s[10000];

bool OK(int x) {
	int tmp = s[x];
	s[x] = -100000;
	int xa = lower_bound(s, s + n, m - tmp) - s;
	if (s[xa] + tmp == m){
		s[x] = tmp;
		return true;
	}
	s[x] = tmp;
	return false;
}
int bins() {
	int mx = 0;
	rep(i,0,n){
		if(OK(i)) {
			if(abs((m - s[i]) - s[i]) < abs((m - mx) - mx)) mx = s[i];
		}
	}

	return mx;
}
void Solution() {
	while (cin >> n) {
		rep(i,0,n)
			cin >> s[i];
		sort(s, s + n);
		cin >> m;
		int mx = bins();

		printf("Peter should buy books whose prices are %d and %d.\n\n",mx,m -  mx
				);
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
