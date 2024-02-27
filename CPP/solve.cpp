/**************************************************************
* CURRENT	: 	13418
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
		p[y] = x;
	else
		p[x] = y;
}


int kruskal() {
	int c = 0, f = 0;
	for(int i=0; i<a.size(); i++) {
		pip cur = a[i];
		int x = cur.second.first;
		int y = cur.second.second;

		if(find_r(x) == find_r(y))
			continue;
		
		union_r(x, y);
		if(cur.first == 0)
			c++;
		f++;
		if(f == n)
			break;
	}
	return c*c;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for(int i=0; i<m+1; i++) {
		int u, v, d;
		cin >> u >> v >> d;	
		a.push_back({d, {u, v}});
	}

	init(n);
	sort(a.begin(), a.end());
	int ans1 = kruskal();

	init(n);
	sort(a.begin(), a.end(), greater<>());
	int ans2 = kruskal();
	
	cout << ans1 - ans2 << "\n";
	return 0;
}
