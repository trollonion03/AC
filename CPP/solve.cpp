/**************************************************************
* CURRENT	: 	16928
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

using namespace std;
constexpr int INF = 0x3f3f3f3f;
typedef long long ll;
typedef unsigned long long ull;

#define NOP ;
#define MAXN 101

int n, m, s, e;
int lds[MAXN];
queue<pair<int,int>> q;
int visited[MAXN];

void bfs() {
	int ans = INF;
	q.push({1, 0});
	visited[1] = true;

	while(!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if(cur == 100) {
			ans = min(ans, cnt);
			break;
		}

		for(int i=1; i<=6; i++) {
			int next = cur + i;

			if(next > 100 || visited[next]) {
				continue;
			}

			visited[next] = true;
			
			if(lds[next] == 0) {
				q.push({next, cnt+1});
				
			}
			else {
				q.push({lds[next], cnt+1});
			}
		}
	}
	cout << ans << "\n";
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	memset(lds, 0, sizeof(lds));
	for(int i=0; i<n; i++) {
		cin >> s >> e;
		lds[s] = e;
	}
	
	bfs();

	return 0;
}