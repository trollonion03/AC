/**************************************************************
* CURRENT	: 	3055
* NEXT 		: 	NULL
***************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>

using namespace std;
constexpr int INF = 0x3f3f3f3f;
typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int,int>
#define NOP ;
#define MAXN 51

typedef struct beaver {
	int x;
	int y;
	int cnt;
};

int n, m;
int ans = INF;
char a[MAXN][MAXN];
bool visited[MAXN][MAXN];
queue<beaver> qb;
queue<pii> qw;
pii sb, sw;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs() {
	qb.push({sb.first, sb.second, 0});
	

	while(!qb.empty()) {
		int bx = qb.front().x;
		int by = qb.front().y;
		int cnt = qb.front().cnt;
		qb.pop();
		

		if(a[bx][by] == 'D') {
			ans = min(ans, cnt);
			continue;
		}

		for(int i=0; i<4; i++) {
			int nbx = bx + dx[i];
			int nby = bx + dy[i];
			int nwx = -1, nwy = -1;
			if(wx != -1 && wy != -1) {
				nwx = wx + dx[i];
				nwy = wy + dy[i];
			}

			bool flag;
			if(nbx >= 0 && nby >= 0 && nbx < n && nby < m && !visited[nbx][nby] && a[nbx][nby] != 'X') {
				for(int j=0; j<4; j++) {
					int cx = nbx + dx[i];
					int cy = nby + dy[i];
					if(!visited[cx][cy] && a[cx][cy] == '*' && a[nbx][nby] != 'D') {
						flag = true;
					}
				}

				if(!flag) {
					qb.push({nbx, nby, cnt+1});
					visited[nbx][nby] = true;
				}
			}

			if(nwx >= 0 && nwy >= 0 && nwx < n && nwy < m && !visited[nwx][nwy]) {
				if(a[nwx][nwy] != 'X' && a[nwx][nwy]) {
					qw.push({nwx, nwy});
					visited[nwx][nwy] = true;
				}
			}
		}
	}

	qw.push(sw);
	
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> a[i][j];
			if(a[i][j] == 'S') {
				sb.first = i;
				sb.second = j;
			}
			if(a[i][j] == '*') {
				sw.first = i;
				sw.second = j;
			}
		}
	}

	bfs();
	if(ans != INF) {
		cout << ans << "\n";
	}
	else {
		cout << "KAKTUS\n";
	}
	
	return 0;
}
