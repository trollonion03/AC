/**************************************************************
* CURRENT	: 	16202
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
#include <deque>

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

int n, m, k;
int p[MAXN];
vector<pair<int, pii>> a;
int ans = 0, c = 0;

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

	if(x < y) {
		p[y] = x;
	}
	else  {
		p[x] = y;
	}
}

int kruskal() {
	int rtn = 0, f = 0;
	for(int i=c; i<a.size(); i++) {
		pair<int, pii> tmp = a[i];

		int f = tmp.second.first;
		int s = tmp.second.second;

		if(find_r(f) == find_r(s))
			continue;
		union_r(f, s);
		rtn += tmp.first;
	}

	for(int i=1; i<=n; i++) {
		if(p[i] == i) {
			f++;
		}
	}
	if(f != 1)
		return 0;
	return rtn;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> k;
	for(int i=0; i<m; i++) {
		int aa, b;
		cin >> aa >> b;
		a.push_back({i+1, {aa, b}});
	}
	sort(a.begin(), a.end());

	for(int i=0; i<k; i++) {
		int tmp = 0;
		bool flag = true;
		if(flag) {
			init(n);
			tmp = kruskal();
			if(tmp == 0)
				flag = false;
			cout << tmp << " ";
			c++;
		}
		else {
			cout << 0 << " ";
		}
	}
	cout << "\n";

	return 0;
}
