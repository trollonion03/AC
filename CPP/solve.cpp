/**************************************************************
* CURRENT	: 	11123
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
#define MAXN 101

int t, n, m;
int cnt = 0;
int a[MAXN][MAXN];
bool visited[MAXN][MAXN];
queue<pair<int, int>> q;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(int x, int y) {
	visited[x][y] = true;
	q.push({x, y});

	while(!q.empty()) {
		int tx = q.front().first;
		int ty = q.front().second;
		q.pop();
		for(int i=0; i<4; i++) {
			int nx = tx + dx[i];
			int ny = ty + dy[i];
			if(nx >= 0 && ny >= 0 && nx < n && ny < m) {
				if(!visited[nx][ny] && a[nx][ny]) {
					visited[nx][ny] = true;
					q.push({nx, ny});
				}
			}
		}
	}
	
}
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> t;
	for(int i=0; i<t; i++) {
		cin >> n >> m;
		for(int j=0; j<n; j++) {
			for(int k=0; k<m; k++) {
				char tmp;
				cin >> tmp;
				if(tmp == '#') {
					a[j][k] = 1;
				}
				else if (tmp == '.') {
					a[j][k] = 0;
				}
			}
		}

		for(int j=0; j<n; j++) {
			for(int k=0; k<m; k++) {
				if(!visited[j][k] && a[j][k]) {
					visited[j][k] = true;
					bfs(j, k);
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
		cnt = 0;
		memset(a, 0, sizeof(a));
		memset(visited, 0, sizeof(visited));
	}
	
	return 0;
}