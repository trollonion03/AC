/**************************************************************
* CURRENT	: 	10775
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

int g, f, d;
int ans = 0;
int p[MAXN];

void init(size_t sz) {
	for(int i=1; i<=sz; i++) {
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

	if(x>y) {
		p[x] = y;
	}
	else {
		p[y] = x;
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> g; 
	cin >> f;
	init(g);

	for(int i=0; i<f; i++) {
		cin >> d;

		int tmp = find_r(d);
		if(tmp) {
			ans++;
			union_r(tmp, tmp-1);
			continue;
		}

		break;
	}

	cout << ans << "\n";
	return 0;
}
