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
#define MAXN 601

int n, m;
int cnt = 0;
string a[MAXN][MAXN];
bool visited[MAXN][MAXN];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int x, int y) {
	
	for(int i=0; i<4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx >= 1 && ny >= 1 && nx <= n && ny <= y) {
			if(v)
		}
		
	}
}
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m; 
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			cin >> a[n][m];
		}
	}

	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			dfs(i, j);
		}
	}
	cout << cnt << "\n";

	return 0;
}