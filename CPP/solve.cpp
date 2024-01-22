/**************************************************************
* CURRENT	: 	13549
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
#define MAXN 100010

int n, m;
priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
int visited[MAXN];

void bfs() {
	pq.push({0, n});
	visited[n] = true;

	while(!pq.empty()) {
		int cnt = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if(cur == m) {
			cout << cnt << "\n";
		}

		int dlx = cur * 2;
		if(dlx <= MAXN-10 && !visited[dlx]) {
			pq.push({cnt, dlx});
			visited[dlx] = true;
		}

		int neg = cur - 1;
		if(neg >= 0 && !visited[neg]) {
			pq.push({cnt+1, neg});
			visited[neg] = true;
		}

		int pos = cur + 1;
		if(pos <= MAXN-10 && !visited[pos]) {
			pq.push({cnt+1, pos});
			visited[pos] = true;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	bfs();

	return 0;
}
