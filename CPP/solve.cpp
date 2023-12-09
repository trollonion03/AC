/**************************************************************
* CURRENT	: 	21736
* NEXT 		: 	15720
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
#define MAXN 602

int n, m;
int cnt = 0;
char a[MAXN][MAXN];
bool visited[MAXN][MAXN];
queue<pair<int, int>> q;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(int i, int j) {
	visited[i][j] = true;

	queue<pair<int, int>> q;
	q.push(pair<int, int>(i, j));

	while (!q.empty()) {
		int nx = q.front().first;
		int ny = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int x = nx + dx[i];
			int y = ny + dy[i];

			if (x >= 0 && y >= 0 && x < n && y < m && visited[x][y] == false) {
				if (a[x][y] == 'X') continue;
				if (a[x][y] == 'P') cnt++;
				visited[x][y] = true;
				q.push(pair<int, int>(x, y));
			}
		}
	}
}
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 'I') {
				bfs(i, j);
			}
		}
	}
	if (cnt == 0) cout << "TT" << endl;
	else cout << cnt << "\n";

	return 0;
}