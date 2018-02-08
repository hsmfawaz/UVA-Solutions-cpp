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
	cin >> n;
	while (n--) {
		string s, res = "";
		cin >> s;
		stack<char> x;

		rep(i,0,sz(s))
		{
			if (s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '^'
					|| s[i] == '*')
				x.push(s[i]);
			else if (s[i] == ')')
				res += x.top(), x.pop();
			else if (s[i] != '(')
				res += s[i];
		}
		cout << res << endl;
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
