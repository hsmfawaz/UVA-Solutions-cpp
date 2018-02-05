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
bool winner(string x) {
	bool row = false, column = false, dig = false;
	for (int i = 0; i < 9; i += 3)
		if (x[i] != '.' and x[i] == x[i + 1] and x[i + 1] == x[i + 2])
			row = true;

	rep(i,0,3)
		if (x[i] != '.' and x[i] == x[i + 3] and x[i + 3] == x[i + 6])
			column = true;

	if ((x[0] != '.' and x[0] == x[4] and x[4] == x[8])
			|| (x[2] != '.' and x[2] == x[4] and x[4] == x[6]))
		dig = true;

	return row || column || dig;
}
void Solution() {
	int n;
	cin >> n;
	while (n--) {
		string board = "";
		rep(i,0,3)
		{
			string t;
			cin >> t;
			board += t;
		}
		queue<pair<string, bool>> q;
		q.push( { ".........", 1 });
		string res = "no";
		while (!q.empty()) {
			pair<string, bool> cur = q.front();
			q.pop();
			if (cur.ft == board) {
				res = "yes";
				break;
			}

			if (winner(cur.ft))
				continue;

			rep(i,0,9)
			{
				if (cur.ft[i] == '.') {
					cur.ft[i] = cur.sd ? 'X' : 'O';
					if(cur.ft[i] == board[i]) q.push( { cur.ft, !cur.sd });
					cur.ft[i] = '.';
				}
			}

		}
		cout << res << endl;
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
