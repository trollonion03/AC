/**************************************************************
* CURRENT	: 	4963
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
#define MAXN 51

int t, n, m;
int a[MAXN][MAXN];
bool visited[MAXN][MAXN];
queue<pii> q;
int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};

void bfs(int x, int y) {
	q.push({x, y});
	visited[x][y] = true;

	while(!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for(int i=0; i<8; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if(nx>=0 && ny>=0 && nx<m && ny<n) {
				if(!visited[nx][ny] && a[nx][ny] == 1) {
					q.push({nx, ny});
					visited[nx][ny] = true;
				}
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for(;;) {
		int cnt = 0;
		cin >> n >> m;
		if(n == 0 && m == 0)
			break;
		for(int i=0; i<m; i++) {
			for(int j=0; j<n; j++) {
				cin >> a[i][j];
			}
		}
		for(int i=0; i<m; i++) {
			for(int j=0; j<n; j++) {
				if(!visited[i][j] && a[i][j] == 1) {
					bfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
		memset(visited, 0, sizeof(visited));
	}
	return 0;
}
