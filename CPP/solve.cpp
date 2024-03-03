/**************************************************************
* CURRENT	: 	1414
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
#define pldp pair<long double, pii>
#define pdd pair<double, double>
#define pff pair<float, float>
#define NOP ;
#define MAXN 51

int n, len = 0;
char c;
int p[MAXN];
vector<pip> a;

void init(size_t size) {
	for(int i=0; i<=size+1; i++) {
		p[i] = i;
	}
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

	cin >> n;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> c;
			if(c == '0')
				continue;
			if(c >= 'a' && c <= 'z'){
				a.push_back({c-'a'+1, {i, j}});
				len += (c - 'a' + 1);
			}
			else{
				a.push_back({c-'A'+27, {i, j}});
				len += (c - 'A' + 27);
			}
		}
	}
	init(n);
	sort(a.begin(), a.end());
	int ans = kruskal();
	if(isGraph())
		cout << len - ans << "\n";
	else
		cout << -1 << "\n";

	return 0;
}
