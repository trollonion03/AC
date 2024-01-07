/**************************************************************
* dijkstra implementation
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
#define MAXN 100000

int num = 6;
vector<pair<int,int>> a[7]; // 간선 정보
int d[7]; // 최소 비용;

void dijkstra(int start) {
	d[start] = 0;
	priority_queue<pair<int, int>> pq; // 힙 구조 사용
	pq.push({start, 0});

	while(!pq.empty()) {
		int cur = pq.top().first;
		int dist = -pq.top().second;
		pq.pop();

		if(d[cur] < dist)
			continue;

		for(int i=0; i<a[cur].size(); i++) {
			int next = a[cur][i].first; //인접 노드
			int ndist = dist + a[cur][i].second; // 인접 노드로 거쳐 가는 비용
			if(ndist < d[next]) {
				d[next] = ndist;
				pq.push({next, -ndist});
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for(int i=1; i<=num; i++) {
		d[i] = INF;
	}

	a[1].push_back({2, 2});
	a[1].push_back({3, 5});
	a[1].push_back({4, 1});

	a[2].push_back({1, 2});
	a[2].push_back({3, 3});
	a[2].push_back({4, 2});

	a[3].push_back({1, 5});
	a[3].push_back({2, 3});
	a[3].push_back({4, 3});
	a[3].push_back({5, 1});
	a[3].push_back({6, 5});

	a[4].push_back({1, 1});
	a[4].push_back({2, 2});
	a[4].push_back({3, 3});
	a[4].push_back({5, 1});

	a[5].push_back({3, 1});
	a[5].push_back({4, 1});
	a[5].push_back({6, 2});

	a[6].push_back({3, 5});
	a[6].push_back({5, 2});

	dijkstra(1);

	for(int i=1; i<=num; i++) {
		cout << d[i] << " ";
	}
	cout << "\n";
	
	return 0;
}