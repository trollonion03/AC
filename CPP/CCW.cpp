/**************************************************************
* CCW implementation
***************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>

using namespace std;
constexpr int INF = 0x3f3f3f3f;
typedef long long ll;
typedef unsigned long long ull;

#define NOP ;
#define MAXN 7
#define pii pair<int, int>
#define pip pair<int, pair<int, int>>

int x, y;

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

	//양수: 시계 반대방향;
	//음수: 시계방향;
	//0:	평행
	NOP;

	return 0;
}