#include <bits/stdc++.h>
using namespace std;
#define sz(a) int((a).size())
#define all(c) (c).begin(),(c).end()
const int oo = 150123;
int b, p, c;
int myPow(int a, int b)
{
	if (b == 0) return 1;

	if (b % 2 == 0)
	{
		int x = myPow(a, b / 2);
		return (x * x) % c;
	}
	else return (a % c * myPow(a, b - 1)) % c;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	while (scanf("%d %d %d", &b, &p, &c) != EOF)
		printf("%d\n", myPow(b, p));
	return 0;
}
