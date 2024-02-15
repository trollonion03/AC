/**************************************************************
* CURRENT	: 	20040
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
#define MAXN 1000001

int p[MAXN];
int n, m;
int ans = 0;

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

bool union_r(int x, int y) {
	x = find_r(x);
	y = find_r(y);

	if(x != y) {
		p[x] = y;
		return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	init(n);
	for(int i=0; i<m; i++) {
		int a, b;
		cin >> a >> b;
		if(union_r(a, b)) {
			ans = i+1;
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}
