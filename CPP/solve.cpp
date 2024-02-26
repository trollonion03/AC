/**************************************************************
* CURRENT	: 	14621
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
#include <cmath>
#include <map>
#include <vector>
#include <queue>

using namespace std;
constexpr int INF = 0x3f3f3f3f;
typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int, int>
#define pip pair<int, pii>
#define pdd pair<double, double>
#define pff pair<float, float>
#define NOP ;
#define MAXN 1001

int n, m;
int p[MAXN];
char prop[MAXN];
vector<pip> a;

void init(size_t size) {
	for(int i=0; i<=size; i++) {
		p[i] = i;
	}
}

int find_r(int x) {
	if(x == p[x])
		return x;
	return p[x] = find_r(p[x]);
}

void union_r(int x, int y) {
	x = find_r(x);
	y = find_r(y);

	if(x < y) 
		p[x] = y;
	else
		p[y] = x;
}

pii kruskal() {
	int ans = 0, f = 0;
	for(int i=0; i<a.size(); i++) {
		pip cur = a[i];
		int x = cur.second.first;
		int y = cur.second.second;

		if(find_r(x) == find_r(y))
			continue;
		
		union_r(x, y);
		f++;
		ans += cur.first;
	}
	return {ans, f};
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	init(n);
	for(int i=1; i<=n; i++) {
		cin >> prop[i];
	}
	for(int i=0; i<m; i++) {
		int u, v, d;
		cin >> u >> v >> d;

		if(prop[u] != prop[v])
			a.push_back({d, {u, v}});
	}
	sort(a.begin(), a.end());
	pii ans = kruskal();
	if(ans.second != n-1) {
		cout << -1 << "\n";
		return 0;
	}
	cout << ans.first << "\n";

	return 0;
}
