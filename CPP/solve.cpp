/**************************************************************
* CURRENT	: 	2206
* NEXT 		: 	NULL
***************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>

using namespace std;
constexpr int INF = 0x3f3f3f3f;
typedef long long ll;
typedef unsigned long long ull;

#define NOP ;
#define MAXN 101

typedef struct st {
	int x;
	int y;
	int cnt;
	bool flag;
};

int n, m;
int ans = INF;
string input;
int a[MAXN][MAXN];
bool visited[MAXN][MAXN];
queue<st> q;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs() {
	q.push({0, 0, 1, 0});
	visited[0][0] = true;

	while(!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int cnt = q.front().cnt;
		bool flag = q.front().flag;
		q.pop();

		if(x == n-1 && y == m-1) {
			ans = min(ans, cnt);
		}

		for(int i=0; i<4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if(nx>=0 && ny>=0 && x<n && y<m && !visited[nx][ny]) {
				if(a[nx][ny] == 0){
					q.push({nx, ny, cnt+1, flag});
					visited[nx][ny] = true;
				}

				if(a[nx][ny] == 1 && !flag) {
					q.push({nx, ny, cnt+1, true});
					visited[nx][ny] = true;
					a[nx][ny] = 0;
				}
			}
		}
	}

	if(ans != INF) {
		cout << ans << "\n";
	}
	else {
		cout << -1 << "\n";
	}
	
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for(int i=0; i<n; i++) {
		cin >> input;
		for(int j=0; j<input.size(); j++) {
			a[i][j] = (int)input[j] - (int)'0';
		}
	}

	bfs();

	return 0;
}