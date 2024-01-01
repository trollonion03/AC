/**************************************************************
* CURRENT	: 	1987
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

using namespace std;
constexpr int INF = 0x3f3f3f3f;
typedef long long ll;
typedef unsigned long long ull;

#define NOP ;
#define MAXN 20

int n, m;
int ans = -1;
char a[MAXN][MAXN];
int visited[26];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int x, int y, int cnt) {
	ans = max(ans, cnt);
	
	for(int i=0; i<4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if(nx>=0 && ny>=0 && nx<n && ny<m) {
			if(visited[a[nx][ny]-'A']==0) {
				visited[a[nx][ny]-'A']++;
				dfs(nx, ny, cnt+1);
				visited[a[nx][ny]-'A']--;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for(int i=0; i<n; i++) {
		for(int j=0;j<m;j++) {
			cin >> a[i][j];
		}
	}

	visited[a[0][0]-'A'] = true;
	dfs(0, 0, 1);
	cout << ans << "\n";
	
	return 0;
}