/**************************************************************
* CURRENT	: 	2644
* NEXT 		: 	15720
***************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cstring>
#include <string>
#include <vector>

using namespace std;
constexpr int INF = 0x3f3f3f3f;
typedef long long ll;
typedef unsigned long long ull;

#define NOP ;
#define MAXN 100000

bool visited[101];
vector<int> a[101];

int cnt = 0;
int n, m, x, y;
int tgt[2];

void dfs(int x, int y, int k) {
	visited[x] = true;

	if(x == y) {
		cnt = k;
	}

	for(int i=0; i<a[x].size(); i++) {
		int tmp = a[x][i];
		if(!visited[tmp]) {
			dfs(tmp, y, k+1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	cin >> tgt[0] >> tgt[1];
	cin >> m;
	for(int i=0; i<n; i++) {
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}

	dfs(tgt[0], tgt[1], 0);

	if(cnt > 0)
		cout << cnt << endl;
	else
		cout << -1 << endl;

	return 0;
}