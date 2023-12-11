/**************************************************************
* CURRENT	: 	7576
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
#define MAXN 1001

typedef struct tp {
	int x;
	int y;
	int cnt;
}tp;

int n, m;
int cnt = 0;
int a[MAXN][MAXN];
bool visited[MAXN][MAXN];
queue<tp> q;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs() {
	while (!q.empty()) {
		tp b = q.front();
		q.pop();
		cnt = max(cnt, b.cnt); 

		for (int i = 0; i < 4; i++) {
			int nx = b.x + dx[i];
			int ny = b.y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < n && ny < m && !visited[nx][ny] && a[nx][ny] != -1) {
				q.push({nx, ny, b.cnt+1});
				visited[nx][ny] = true;
			}
		}
	}
}
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if(a[i][j] == 1) {
				visited[i][j] == true;
				q.push({i, j, 0});
			}
			else if(a[i][j] == -1) {
				visited[i][j] == true;
			}
		}
	}

	if(q.empty()) {
		cout << "-1\n";
		return 0;
	}
	bfs();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if(!visited[i][j]) {
				cout << "-1\n";
				return 0;
			}
		}
	}

	cout << cnt << "\n";
	
	return 0;
}