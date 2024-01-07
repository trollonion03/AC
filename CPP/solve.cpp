/**************************************************************
* CURRENT	: 	1753
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
// constexpr int INF = 0x3f3f3f3f;
constexpr int INF = 987654321;
typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int,int>
#define NOP ;
#define MAXN 20001

int n, m, st;
vector<pair<int,int>> a[300001];
int d[MAXN];
bool visited[MAXN];

void dijkstra(int start) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	d[start] = 0;
	pq.push({0, start});

	while(!pq.empty()) {
		int dist = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if(d[cur] < dist)
			continue;

		for(int i=0; i<a[cur].size(); i++) {
			int next = a[cur][i].first; 
			int ndist = dist + a[cur][i].second;
			if(ndist < d[next]) {
				d[next] = ndist;
				pq.push({-ndist, next});
			}
		}
	}

	for(int i=1; i<=n; i++) {
		if(d[i] == INF)
			cout << "INF\n";
		else
			cout << d[i] << "\n";
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> st;

	for(int i=0; i<m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		a[u].push_back({v, w});
	}

	for(int i=1; i<=n; i++) {
		d[i] = INF;
	}

	dijkstra(st);

	return 0;
}