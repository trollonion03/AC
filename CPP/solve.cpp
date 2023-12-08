/**************************************************************
* CURRENT	: 	11724
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
#define MAXN 1001

int n, m, u, v;
int cnt = 0;
vector<int> a[MAXN];
bool visited[MAXN];
queue<int> q;

void bfs(int x) {
	q.push(x);
	visited[x] = true;

	while(!q.empty()) {
		int tmp = q.front();
		q.pop();
		for(int i=0; i<a[tmp].size(); i++) {
			int nxt = a[tmp][i];
			if(!visited[nxt]) {
				q.push(nxt);
				visited[nxt] = true;
			}
		}
	}
}
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m; 
	for(int i=0; i<m; i++) {
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	for(int i=1; i<=n; i++) {
		if(!visited[i]) {
			bfs(i);
			cnt++;
		}
	}
	cout << cnt << "\n";

	return 0;
}