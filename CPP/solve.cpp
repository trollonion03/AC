/**************************************************************
* CURRENT	: 	17387
* NEXT 		: 	NULL
***************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <map>
#include <vector>
#include <stack>

using namespace std;
constexpr int INF = 0x3f3f3f3f;
typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int, int>
#define pip pair<int, pii>
#define NOP ;
#define MAXN 200001

typedef struct pos {
	ll x;
	ll y;
};

pos p1, p2, p3, p4;
int a, b, c, d;
bool ans;

int ccw(pos p1, pos p2, pos p3) {
	ll tmp = (p2.x-p1.x) * (p3.y-p1.y) - (p3.x-p1.x) * (p2.y - p1.y);
	if(tmp > 0)
		return 1;
	if(tmp < 0)
		return -1;
	return 0;
}

bool checkLine(int a, int b, int c, int d) {
	if(a > b)
		swap(a, b);
	if(c > d)
		swap(c, d);
	bool n = a<=d && b>=c;
	bool m = c<=b && d>=a;
	return n || m;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> p1.x >> p1.y >> p2.x >> p2.y;
	cin >> p3.x >> p3.y >> p4.x >> p4.y;

	a = ccw(p1, p2, p3);
	b = ccw(p1, p2, p4);
	c = ccw(p3, p4, p1);
	d = ccw(p3, p4, p2);

	if(a*b == 0 && c*d == 0)
		ans = checkLine(p1.x, p2.x, p3.x, p4.x) && checkLine(p1.y, p2.y, p3.y, p4.y);
	else {
		bool tmp1, tmp2;
		tmp1 = a*b <= 0;
		tmp2 = c*d <= 0;
		ans = tmp1 && tmp2;
	}

	cout << ans << "\n";
	
	return 0;
}
