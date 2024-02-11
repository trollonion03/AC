/**************************************************************
* CURRENT	: 	1647
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
#include <stack>

using namespace std;
constexpr int INF = 0x3f3f3f3f;
typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int,int>
#define NOP ;
#define MAXN 100001

int n, m, ans = 0;
int p[MAXN];
vector<pair<int, pii>> a;
vector<pair<int, pii>> mst;

void init() {
	for(int i=1; i<=n; i++) {
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
	
	if(x != y)
		p[y] = x;
}

void kruskal() {
	for(int i=0; i<a.size(); i++) {
		pair<int, pii> cur = a[i];

		int f = cur.second.first;
		int s = cur.second.second;

		if(find_r(f) == find_r(s))
			continue;
		mst.push_back(cur);
		union_r(f, s);

		if(mst.size() == n-1)
			return;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	init();
	for(int i=0; i<m; i++) {
		int aa, b, c;
		cin >> aa >> b >> c;
		a.push_back({c, {aa, b}});
	}
	sort(a.begin(), a.end());
	kruskal();
	for(int i=0; i<mst.size()-1; i++) {
		ans += mst[i].first;
	}
	cout << ans << "\n";
	
	return 0;
}
