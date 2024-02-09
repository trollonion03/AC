/**************************************************************
* Union-Find implementation
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

int parent[MAXN];
int node_rank[MAXN];

int find_root(int x) {
	if(x == parent[x])
		return x;
	return
		parent[x] = find_root(parent[x]);
}

void union_root(int x, int y) {
	//x, y 정점의 최상위 정점을 탐색
	x = find_root(x);
	y = find_root(y);

	if (x != y) {
#if 0
		parent[x] = y;
#endif
		//서로 다른 트리에 속한다면, 한쪽의 트리를 다른쪽에 붙인다.
		//낮은 트리를 높은 트리에 붙인다.
		if(node_rank[x] < node_rank[y])
			parent[x] = y;
		else
			parent[y] = x;
		
		//합친 두 트리의 높이가 같다면 합친 후 높이를 1 증가
		if(node_rank[x] == node_rank[y]) {
			parent[x] = y;
			node_rank[x]++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	
	return 0;
}