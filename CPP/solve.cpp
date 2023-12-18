/**************************************************************
* CURRENT	: 	10026
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

typedef struct container {
	int x;
	int y;
	// R:1, G:2, B:3
};

int n;
int cnt = 0;
char ch;
int a[MAXN][MAXN];
bool visited[MAXN][MAXN];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(int x, int y, int clr, bool state) {
	queue<container> q;
	q.push({x, y});
	visited[x][y] = true;

	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		q.pop();

		for(int i=0; i<4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if(nx>=0 && ny>=0 && nx<n && ny<n && !visited[nx][ny]) {
				if(!state) {
					if(a[nx][ny] == clr) {
						visited[nx][ny] = true;
						q.push({nx, ny});
					}
				}
				else {
					if(clr == 1 || clr == 2) {
						if (a[nx][ny] == 1 || a[nx][ny] == 2) {
							visited[nx][ny] = true;
							q.push({nx, ny});
						}
					}
					else {
						if(a[nx][ny] == clr) {
							visited[nx][ny] = true;
							q.push({nx, ny});
						}
					}
				}
			}
		}


	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> ch;
			if(ch == 'R') {
				a[i][j] = 1;
			}
			else if(ch == 'G') {
				a[i][j] = 2;
			}
			else if(ch == 'B') {
				a[i][j] = 3;
			}
		}
	}

	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(!visited[i][j]) {
				bfs(i, j, a[i][j], false);
				cnt++;
			}
		}
	}

	cout << cnt << " ";
	cnt = 0;
	memset(visited, 0, sizeof(visited));

	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(!visited[i][j]) {
				bfs(i, j, a[i][j], true);
				cnt++;
			}
		}
	}
	cout << cnt << "\n";

	return 0;
}