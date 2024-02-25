/**************************************************************
* CURRENT	: 	1799
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
#include <cmath>
#include <map>
#include <vector>
#include <queue>

using namespace std;
constexpr int INF = 0x3f3f3f3f;
typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int, int>
#define pip pair<int, pii>
#define pdd pair<double, double>
#define pff pair<float, float>
#define NOP ;
#define MAXN 11

int n;
int ans[2];
int a[MAXN][MAXN];
bool visited[2][MAXN*2];
int dx[4] = {1, -1, 1, -1};
int dy[4] = {1, -1, -1, 1};

void setV(bool f, int a, int b) {
	visited[0][a] = f;
	visited[1][b] = f;
}

void check(int cnt, int clr, int x, int y) {
	if(x >= n) {
		y++;
		if(x%2 == 0)
			x = 1;
		else x = 0;
	}
	if(y >= n) {
		ans[clr] = max(cnt, ans[clr]);
		return;
	}
	if(a[y][x] == 1 && !visited[0][x+y+1] && !visited[1][x-y+n]) {
		setV(1, x+y+1, x-y+n);
		check(cnt+1, clr, x+2, y);
		setV(0, x+y+1, x-y+n);
	}
	check(cnt, clr, x+2, y);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> a[i][j];
		}
	}

	check(0, 0, 0, 0);
	check(0, 1, 1, 0);

	cout << ans[0]+ans[1] << "\n";
	return 0;
}
