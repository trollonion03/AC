/**************************************************************
* CURRENT	: 	11758
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
#include <vector>
#include <stack>

using namespace std;
constexpr int INF = 0x3f3f3f3f;
typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int,int>
#define NOP ;
#define MAXN 100001

int x1, x2, x3, y1, y2, y3;

typedef struct coord {
	int x;
	int y;
};

int ccw(coord p1, coord p2, coord p3) {
	return (p2.x-p1.x) * (p3.y-p1.y) - (p3.x-p1.x) * (p2.y - p1.y);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> x1 >> y1;
	cin >> x2 >> y2;
	cin >> x3 >> y3;

	int tmp = ccw({x1, y1}, {x2, y2}, {x3, y3});
	if(tmp > 0) {
		cout << 1 << "\n";
		return 0;
	}
	if(tmp == 0) {
		cout << 0 << "\n";
		return 0;
	}
	if(tmp < 0) {
		cout << -1 << "\n";
		return 0;
	}
	
	return 0;
}
