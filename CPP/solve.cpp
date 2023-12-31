/**************************************************************
* CURRENT	: 	2638
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

int n, m;
int cnt = 0;
int a[MAXN][MAXN];
queue<pair<int, int>> q;
vector<pair<int, int>> v;
bool visited[MAXN][MAXN];
int outside[MAXN][MAXN];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfsAir() {
	q.push({0, 0});
	visited[0][0] = true;

	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for(int i=0; i<4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if(nx >= 0 && ny >= 0 && nx < n && ny < m && !visited[nx][ny]) {
				if(a[nx][ny] == 1) {
					outside[nx][ny]++;
				}
				else {
					q.push({nx, ny});
					visited[nx][ny] = true;
					if (a[nx][ny] == 0) {
						a[nx][ny] = 5;
					}
				}
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
		}
	}

	bool flag = false;
	for(;;) {
		bfsAir();
		for(int i=1; i<n-1; i++) {
			for(int j=1; j<m-1; j++) {
				if(outside[i][j] >= 2) {
					flag = true;
					a[i][j] = 0;
				}
			} 
		}

		if(flag) {
			cnt++;
		}
		else {
			break;
		}

		memset(visited, 0, sizeof(visited));
		memset(outside, 0, sizeof(outside));
		flag = false;
	}	

	cout << cnt << "\n";

	return 0;
}