/**************************************************************
* CURRENT	: 	3055
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
#include <queue>

using namespace std;
constexpr int INF = 0x3f3f3f3f;
typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int,int>
#define NOP ;
#define MAXN 51

typedef struct beaver {
	int x;
	int y;
	int cnt;
};

int n, m;
int ans = INF;
char a[MAXN][MAXN];
int mp[MAXN][MAXN];
bool visited[MAXN][MAXN];
queue<beaver> qb;
queue<beaver> qw;
pii sb, sw = {-1, -1};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs() {
	// 구역별 물이 차오르는 시간 계산
	while(!qw.empty()) {
		int x = qw.front().x;
		int y = qw.front().y;
		int cnt = qw.front().cnt;
		qw.pop();

		for(int i=0; i<4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if(nx>=0 && ny>=0 && nx<n && ny<m && !visited[nx][ny]) {
				if(a[nx][ny] == 'D' || a[nx][ny] == 'X') {
					mp[nx][ny] = -1;
					continue;
				}
				mp[nx][ny] = cnt+1;
				qw.push({nx, ny, cnt+1});
				visited[nx][ny] = true;
			}
		}
	}
	memset(visited, 0, sizeof(visited));

	qb.push({sb.first, sb.second, 0});
	visited[sb.first][sb.second] = true;

	while(!qb.empty()) {
		int x = qb.front().x;
		int y = qb.front().y;
		int cnt = qb.front().cnt;
		qb.pop();

		if(a[x][y] == 'D') {
			ans = min(ans, cnt);
		}

		for(int i=0; i<4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if(nx>=0 && ny>=0 && nx<n && ny<m && !visited[nx][ny]) {
				if((mp[nx][ny] > 0 && cnt+1 >= mp[nx][ny]) || a[nx][ny] == 'X') {
					continue;
				}
				qb.push({nx, ny, cnt+1});
				visited[nx][ny] = true;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> a[i][j];
			if(a[i][j] == 'S') {
				sb.first = i;
				sb.second = j;
			}
			if(a[i][j] == '*') {
				qw.push({i, j, 0});
				visited[i][j] = true;
			}
		}
	}

	bfs();
	if(ans != INF) {
		cout << ans << "\n";
	}
	else {
		cout << "KAKTUS\n";
	}
	
	return 0;
}
