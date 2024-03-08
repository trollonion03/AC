/**************************************************************
* CURRENT	: 	10021
* NEXT 		: 	NULL
***************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <memory.h>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cmath>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;
constexpr int INF = 0x3f3f3f3f;
typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int, int>
#define pip pair<int, pii>
#define plp pair<ll, pii>
#define pldp pair<long double, pii>
#define pdd pair<double, double>
#define pff pair<float, float>
#define NOP ;
#define MAXN 2001

int n, m;
int t = 0;
int p[MAXN];
vector<plp> a;
vector<pii> pnt;

void init(size_t size) {
	for(int i=0; i<=size+1; i++) {
		p[i] = i;
	}
}

ll getDist(pii p1, pii p2) {
	return pow(p1.first-p2.first, 2) + pow(p1.second-p2.second, 2);
}

int find_r(int x) {
	if(x == p[x])
		return x;
	return p[x] = find_r(p[x]);
}

bool isGraph() {
	for(int i=1; i<n; i++) {
		if(find_r(i) != find_r(0)) {
			return false;
		}
	}
	return true;
}

void union_r(int x, int y) {
	x = find_r(x);
	y = find_r(y);

	if(x < y) 
		p[y] = x;
	else
		p[x] = y;
}

ll kruskal() {
	ll rtn = 0, cnt = 0;
	for(int i=0; i<a.size(); i++) {
		plp cur = a[i];
		int x = cur.second.first;
		int y = cur.second.second;
		
		if(find_r(x) == find_r(y))
			continue;
		union_r(x, y);
		rtn += cur.first;
		cnt++;
		if(cnt == n-1)
			break;
	}
	if(cnt != n-1)
		return -1;
	return rtn;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for(int i=0; i<n; i++) {
		int u, v;
		cin >> u >> v;
		pnt.push_back({u, v});
	}
	for(int i=0; i<n-1; i++) {
		pii c1 = pnt[i]; 
		for(int j=i+1; j<n; j++) {
			pii c2 = pnt[j];
			ll dist = getDist(c1, c2);
			if(dist >= m)
				a.push_back({dist, {i, j}});
		}
	}

	sort(a.begin(), a.end());
	init(n);
	ll ans = kruskal();
	cout << ans << "\n";

	return 0;
}
