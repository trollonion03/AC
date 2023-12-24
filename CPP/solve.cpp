/**************************************************************
* CURRENT	: 	1697
* NEXT 		: 	7569
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
#define MAXN 100001

int n, m;
int ans = INF;
queue<pair<int, int>> q;
int visited[MAXN];

void bfs() {
	q.push({n, 0});
	visited[n] = false;

	while(!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if(cur == m) {
			ans = min(ans, cnt);
		}

		int neg = cur - 1;
		if(neg < MAXN && neg >= 0 && !visited[neg]) {
			q.push({neg, cnt+1});
			visited[neg] = true;
		}

		int pos = cur + 1;
		if(pos < MAXN && pos >= 0 && !visited[pos]) {
			q.push({pos, cnt+1});
			visited[pos] = true;
		}

		int dlx = cur * 2;
		if(dlx < MAXN && dlx >= 0 && !visited[dlx]) {
			q.push({dlx, cnt+1});
			visited[dlx] = true;
		}
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	bfs();

	return 0;
}