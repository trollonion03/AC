/**************************************************************
* CURRENT	: 	1303
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
#include <set>

using namespace std;
constexpr int INF = 0x3f3f3f3f;
typedef long long ll;
typedef unsigned long long ull;

#define NOP ;
#define MAXN 101

int n, m;
string s;
int a[MAXN][MAXN];
bool visited[MAXN][MAXN];
queue<pair<int, int>> q;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int wcnt = 0, bcnt = 0;
int ctmp = 0;

void bfs(int x, int y, int tgt) {
    visited[x][y] = true;
    q.push({x, y});
    ctmp++;

    while(!q.empty()) {
        int xtmp = q.front().first;
        int ytmp = q.front().second;
        q.pop();
        for(int i=0; i<4; i++) {
            int nx = xtmp + dx[i];
            int ny = ytmp + dy[i];
            if(nx>=0 && ny>=0 && nx<m && ny<n && !visited[nx][ny] && a[nx][ny] == tgt) {
                visited[nx][ny] = true;
                q.push({nx, ny});
                ctmp++;
            }
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++) {
        cin >> s;
        for(int j=0; j<m; j++) {
            if(s[j] == 'W') {
                a[i][j] = 1;
            }
            else if(s[j] == 'B') {
                a[i][j] = 0;
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(!visited[i][j]) {
                bfs(i, j, a[i][j]);
                if(a[i][j]) {
                    wcnt += ctmp * ctmp;
                }
                else {
                    bcnt += ctmp * ctmp;
                }
                ctmp = 0;
            }
        }
    }
    
    cout << wcnt << " " << bcnt << "\n";	
	return 0;
}