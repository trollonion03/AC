/**************************************************************
* MST-Kruskal implementation
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
#define MAXN 7
#define pii pair<int, int>
#define pip pair<int, pair<int, int>>

int v = MAXN-1;
int parent[MAXN];
vector<pip> edges;

void init() {
	for(int i=1; i<=6; i++) {
		parent[i] = i;
	}
}

int find_r(int x) {
	if(x == parent[x])
		return x;
	return
		parent[x] = find_r(parent[x]);
}

void union_r(int x, int y) {
	x = find_r(x);
	y = find_r(y);

	if (x != y)
		parent[y] = x;

}

vector<pip> kruskal() {
	vector<pip> mst;

	for(int i=0; i<edges.size(); i++) {
		pip cur = edges[i];

		int f = cur.second.first;
		int s = cur.second.second;

		if(find_r(f) == find_r(s))
			continue;
		
		mst.push_back(cur);
		union_r(f, s);
		
		if(mst.size() == v - 1)
			return mst;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	init();
	
	return 0;
}