/**************************************************************
* CURRENT	: 	1774
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
#include <map>
#include <vector>
#include <queue>

using namespace std;
constexpr int INF = 0x3f3f3f3f;
typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int, int>
#define pip pair<int, pii>
#define pldp pair<long double, pii>
#define pdd pair<double, double>
#define pff pair<float, float>
#define NOP ;
#define MAXN 1001

int n, m;
int p[MAXN];
vector<pldp> a;
vector<pii> b;
vector<pii> c;

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
		p[y] = x;
	else
		p[x] = y;
}

long double getDist(pii p1, pii p2) {
	return sqrt(pow(p1.first-p2.first, 2) + pow(p1.second-p2.second, 2));
}

long double kruskal() {
	long double rtn = 0;
	for(int i=0; i<a.size(); i++) {
		pldp cur = a[i];
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

	cin >> n >> m;
	init(n);
	for(int i=0; i<n; i++) {
		int u, v;
		cin >> u >> v;	
		b.push_back({u, v});
	}
	for(int i=0; i<m; i++) {
		int u, v;
		cin >> u >> v;
		c.push_back({u, v});
	}

	for(int i=0; i<m; i++) {
		int x = find_r(c[i].first);
		int y = find_r(c[i].second);

		if(x != y)
			union_r(x, y);
	}

	pii p1, p2;
	for(int i=0; i<n-1; i++) {
		p1 = b[i];
		for(int j=i+1; j<n; j++) {
			p2 = b[j];
			long double dist = getDist(p1, p2);
			a.push_back({dist, {i+1, j+1}});
		}
	}

	sort(a.begin(), a.end());
	long double ans = kruskal();

	cout << fixed;
	cout << setprecision(2);
	cout << round(ans*100)/100 << endl;

	return 0;
}
