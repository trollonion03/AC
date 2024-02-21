/**************************************************************
* CURRENT	: 	4386
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
#define MAXN 101

int n;
int p[MAXN];
vector<pff> a;
vector<pair<float, pii>> b;
float ans = 0;

void init(int x) {
	for(int i=0; i<=n; i++) {
		p[i] = i;
	}
}

int find_r(int x) {
	if(p[x] == x)
		return x;
	return p[x] = find_r(p[x]);
}

void union_r(int x, int y) {
	x = find_r(x);
	y = find_r(y);

	if(x > y) {
		p[x] = y;
	}
	else {
		p[y] = x;
	}
}

float kruskal() {
	float rtn = 0;
	for(int i=0; i<b.size(); i++) {
		pair<float, pii> tmp = b[i];

		int f = tmp.second.first;
		int s = tmp.second.second;

		if(find_r(f) == find_r(s))
			continue;
		union_r(f, s);
		rtn += tmp.first;
	}
	return rtn;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	init(n);
	for(int i=0; i<n; i++) {
		float t1, t2;
		cin >> t1 >> t2;
		a.push_back({t1, t2});
	}

	for(int i=0; i<n; i++) {
		for(int j=i+1; j<n; j++) {
			pdd t1 = a[i], t2 = a[j];
			float dst = pow(t2.first - t1.first, 2) + pow(t2.second - t1.second, 2);
            dst = sqrtf(dst);
			b.push_back(make_pair(dst, make_pair(i, j)));
		}
	}

	sort(b.begin(), b.end());
	ans = kruskal();

	cout << fixed;
	cout.precision(2);
	cout << ans << "\n";

	return 0;
}
