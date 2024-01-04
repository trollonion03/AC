/**************************************************************
* CURRENT	: 	16236
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

#define pii pair<int,int>
#define NOP ;
#define MAXN 21

typedef struct ct {
	int x;
	int y;
	int time;
};

typedef struct shark {
	int size;
	int cnt;
};

int n;
int a[MAXN][MAXN];
int ans = 0;

shark bShark = {2, 0};
pii start;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};


int bfs() {
	queue<ct> q;
	bool visited[MAXN][MAXN] = {0,};
	bool flag = false;
	int cost = 0;
	
	q.push({start.first, start.second, 0});
	visited[start.first][start.second] = true;

	while(!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int time = q.front().time;
		q.pop();

		for(int i=0; i<4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if(nx>=0 && ny>=0 && nx<n && ny<n && !visited[nx][ny]) {
				if(a[nx][ny] > 0 && a[nx][ny] < bShark.size) {
					if(!flag) {
						flag = true;
						start.first = nx;
						start.second = ny;
						cost = time+1;
						visited[nx][ny] = true;
					}
					else {
						if(time+1 <= cost && (nx < start.first || (ny < start.second && nx == start.first))) {
							start.first = nx;
							start.second = ny;
							cost = time+1;
							visited[nx][ny] = true;
						}
					}
				}
				else if(a[nx][ny] >= 0 && a[nx][ny] <= bShark.size) {
					q.push({nx, ny, time+1});
					visited[nx][ny] = true;
				}
			}
		}
	}
	return cost;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> a[i][j];
			if(a[i][j] == 9) {
				start.first = i;
				start.second = j;
				a[i][j] = 0;
			}
		}
	}
 
	int able;
	while(true) {
		able = bfs();
		if(able == 0)
			break;
		else {
			a[start.first][start.second] = 0;
			ans += able;
			bShark.cnt += 1;
			if(bShark.size == bShark.cnt) {
				bShark.size++;
				bShark.cnt = 0;
			}
		}
	}
	cout << ans << "\n";

	return 0;
}