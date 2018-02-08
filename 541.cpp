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
typedef unsigned long long ll;
typedef unsigned long ul;
const int MX = 10e5 + 1;
void Solution() {
	int n;
	while (cin >> n, n) {
		int x[100][100];
		rep(i,0,n)
			rep(j,0,n)
				cin >> x[i][j];

		int row[100], column[100];
		clr(row), clr(column);
		rep(i,0,n)
		{
			rep(j,0,n)
			{
				row[i] += x[i][j];
				column[i] += x[j][i];
			}
		}
		int sumr = 0, sumc = 0, idxr, idxc;
		rep(i,0,n)
		{
			if (row[i] % 2)
				sumr++, idxr = i;
			if (column[i] % 2)
				sumc++, idxc = i;
		}

		if (sumr == 0 and sumc == 0)
			cout << "OK\n";
		else if (sumr == 1 and sumc == 1)
			cout <<"Change bit ("<<idxr + 1 <<","<<idxc + 1 <<")\n";
		else
			cout << "Corrupt" << endl;

	}
}
int main() {
	FastIO;
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	Solution();
	return 0;
}
