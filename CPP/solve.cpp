/**************************************************************
* CURRENT	: 	4195
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
#include <map>
#include <vector>
#include <stack>

using namespace std;
constexpr int INF = 0x3f3f3f3f;
typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int, int>
#define pip pair<int, pii>
#define NOP ;
#define MAXN 200001

int t, f;
string tmp1, tmp2;
map<string, int> m;
int p[MAXN];
int fnum[MAXN];

void init(size_t s) {
	for(int i=0; i<=s*2; i++) {
		p[i] = i;
		fnum[i] = 1;
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
	if(x > y) {
		p[x] = y;
		fnum[y] += fnum[x];
	}
	else if(x < y) {
		p[y] = x;
		fnum[x] += fnum[y];
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> t;
	while(t--) {
		m.clear();
		int idx = 0, a=0, b=0;
		cin >> f;
		init(f);
		for(int i=0; i<f; i++) {
			cin >> tmp1 >> tmp2;
			
			if(m.find(tmp1) == m.end()) {
				m[tmp1] = ++idx;
			}
			a = m[tmp1];

			if(m.find(tmp2) == m.end()) {
				m[tmp2] = ++idx;
			}
			b = m[tmp2];
			
			union_r(a, b);
			int index = find_r(a);
			cout << fnum[index] << "\n";	
		}
	}
	
	return 0;
}
