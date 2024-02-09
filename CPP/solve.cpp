/**************************************************************
* CURRENT	: 	1717
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
#define MAXN 1000001

int n, m;
int p[MAXN];
int a, b, c;

void init() {
	for(int i=1; i<=n; i++) {
		p[i] = i;
	}
}

int find_r(int x) {
	if(x == p[x])
		return x;
	return p[x] = find_r(p[x]);
}

bool check_union(int x, int y) {
	x = find_r(x);
	y = find_r(y);
	if(x == y) {
		return true;
	}
	return false;

}

void union_r(int x, int y) {
	x = find_r(x);
	y = find_r(y);
	if(x>y) {
		p[x] = y;
		return;
	}
	p[y] = x;
}



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	init();
	for(int i=0; i<m; i++) {
		cin >> a >> b >> c;
		if(a) {
			bool flag = check_union(b, c);
			if(flag)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
		else {
			union_r(b, c);
		}
	}
	
	return 0;
}
