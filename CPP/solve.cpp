/**************************************************************
* CURRENT	: 	2468
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

int a[101][101];
bool visited[101][101];
int n, cnt, minh, maxh;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0,  0, 1, -1};
vector<int> tmp;
int res = 0;

void dfs(int y, int x, int h) {
	for(int i=0; i<n; i++) {
		int nx = x + dx[i];
		int ny = x + dy[i];

		if(nx >= 0 && ny >= 0 && nx < n && ny < n) {
			if(!visited[ny][nx] && a[ny][nx] > h) {
				visited[ny][nx] = true;
				dfs(ny, nx, h);
			}
		}
	}
}

void init() {
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			visited[i][j] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> a[i][j];
			tmp.push_back(a[i][j]);

		}
	}

	int minh = *min_element(tmp.begin(), tmp.end());	
	int maxh = *max_element(tmp.begin(), tmp.end());

	for(int h=minh; h<maxh; h++) {
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				if(!visited[i][j]) {
					visited[i][j] = true;
					dfs(j, i, h);
					cnt++;
				}
			}
		}
		if(cnt == 0)
			break;
		if(res < cnt)
			res = cnt;
		cnt = 0;
		init();
	}
	
	
	cout << res << endl;

	return 0;
}