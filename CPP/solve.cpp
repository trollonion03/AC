/**************************************************************
* CURRENT	: 	1926
* NEXT 		: 	15720
***************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cstring>
#include <string>
#include <vector>

using namespace std;
constexpr int INF = 0x3f3f3f3f;
typedef long long ll;
typedef unsigned long long ull;

#define NOP ;
#define MAXN 100000

bool visited[501][501];
bool a[501][501];
vector<int> vec;

int dy[4]{0, 0, 1, -1};
int dx[4]{1, -1, 0, 0};

int cnt = 0;
int lw = 0;
int n, m;

void dfs(int y, int x) {
	visited[y][x] = true;

	for(int i=0; i<4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m)
            continue;
        if (a[ny][nx] == 1 && visited[ny][nx] == 0) {
            visited[ny][nx] = true;
            lw++;
            dfs(ny, nx);
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

	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(a[i][j] && !visited[i][j]) {
				dfs(i, j);
				cnt++;
				vec.push_back(lw);
				lw = 1;
			}
		}
	}

	sort(vec.rbegin(), vec.rend());
	cout << cnt << endl;
	
	if(cnt > 0)
		cout << vec[0] << endl;
	else
		cout << 0 << endl;

	return 0;
}