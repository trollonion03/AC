/**************************************************************
* CURRENT	: 	4792
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

int n, m, k;
int t = 0;
int p[MAXN];
vector<pip> a;

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

int kruskal() {
	int rtn = 0;
	for(int i=0; i<a.size(); i++) {
		pip cur = a[i];
		int x = cur.second.first;
		int y = cur.second.second;
		
		if(find_r(x) == find_r(y))
			continue;
		union_r(x, y);
		rtn += cur.first;
	}
	return rtn;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	while(true) {
		cin >> n >> m >> k;
		if(n == 0 && m == 0 && k == 0)
			break;
		for(int i=0; i<m; i++) {
			int u, v;
			char ch;
			int cst;
			cin >> ch >> u >> v;
			if(ch == 'R') cst = 0;
			else cst = 1;
			a.push_back({cst, {u, v}});
		}

		sort(a.begin(), a.end());
		init(n);
		int minv = kruskal();
		
		sort(a.begin(), a.end(), greater<>());
		init(n);
		int maxv = kruskal();

		if(k >= minv && k <= maxv)
			cout << 1 << "\n";
		else
			cout << 0 << "\n";

		a.clear();
	}
	return 0;
}
