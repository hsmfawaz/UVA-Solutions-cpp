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
const int oo = 1025;
int t, d, n, x, y, z, rx, ry;
int res[oo][oo];
void solution() {
	scanf("%d", &t);
	rep(tt,0,t)
	{
		clr(res);
		int mnx, mxx, mny, mxy, mn = 0;
		scanf("%d %d", &d, &n);
		rep(i,0,n)
		{
			scanf("%d %d %d", &x, &y, &z);
			mnx = max(0, x - d), mxx = min(1024, x + d);
			mny = max(0, y - d), mxy = min(1024, y + d);
			rep(i,mnx,mxx+1)
				rep(j,mny,mxy+1)
					res[i][j] += z;
		}

		rep(i,0,oo)
			rep(j,0,oo)
				if (res[i][j] > mn)
					mn = res[i][j], rx = i, ry = j;

		printf("%d %d %d\n", rx, ry, mn);
	}
}
int main() {
	FastIO;
	solution();
	return 0;
}
