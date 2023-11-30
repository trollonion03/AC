/**************************************************************
* CURRENT	: 	1012
* NEXT 		: 	15720
***************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;
constexpr int INF = 0x3f3f3f3f;
typedef long long ll;
typedef unsigned long long ull;

#define NOP ;
#define MAXN 100000

bool visited[51][51];
bool a[51][51];

int dx[4]{0, 0, 1, -1};
int dy[4]{1, -1, 0, 0};

int cnt = 0;
int n, m, c, t;
int x, y;


void dfs(int y, int x) {
	if(visited[y][x])
		return;

	for(int i=0; i<4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if(nx >= 0 && ny >= 0 && nx < n && ny < m) {
			if(a[ny][nx]) {
				dfs(ny, nx);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> t;
	for(int i=0; i<t; i++) {
		cin >> n >> m >> c;
		for(int j=0; j<c; j++) {
			cin >> x >> y;
			a[y][x] = 1;
		}
		for(int j=0; j<n; j++) {
			for(int k=0; k<m; k++) {
				if(a[j][k] && !visited[j][k]) {
					dfs(j, k);
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}