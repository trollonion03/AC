/**************************************************************
* CURRENT	: 	2887
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

#define pii pair<int, int>
#define pip pair<int, pii>
#define NOP ;
#define MAXN 100001

int p[MAXN];
int n, ans = 0;
vector<pii> vx;
vector<pii> vy;
vector<pii> vz;
vector<pip> mst;

void init(int x) {
	for(int i=0; i<x; i++) {
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

	if(x != y)
		p[x] = y;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	//init(n);
	for(int i=1; i<=n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		vx.push_back({x, i});
		vy.push_back({y, i});
		vz.push_back({z, i});
		p[i] = i;
	}
	sort(vx.begin(), vx.end());
	sort(vy.begin(), vy.end());
	sort(vz.begin(), vz.end());

	for(int i=0; i<n-1; i++) {
		mst.push_back({abs(vx[i].first - vx[i+1].first), {vx[i].second, vx[i+1].second}});
		mst.push_back({abs(vy[i].first - vy[i+1].first), {vy[i].second, vy[i+1].second}});
		mst.push_back({abs(vz[i].first - vz[i+1].first), {vz[i].second, vz[i+1].second}});
		
	}
	sort(mst.begin(), mst.end());

	for(int i=0; i<mst.size(); i++) {
		int a = find_r(mst[i].second.first);
		int b = find_r(mst[i].second.second);
		
		if(a != b) {
			union_r(mst[i].second.first, mst[i].second.second);
			ans += mst[i].first;
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}
