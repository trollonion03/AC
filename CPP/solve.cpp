/**************************************************************
* CURRENT	: 	16953
* NEXT 		: 	NULL
***************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>

using namespace std;
constexpr int INF = 0x3f3f3f3f;
typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int,int>
#define NOP ;
#define MAXN 10000000001

ll n, m;
int ans = INF;
queue<pair<ll, int>> q;

void bfs() {
	q.push({n, 0});

	while(!q.empty()) {
		ll cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if(cur == m) {
			ans = min(ans, cnt);
		}

		ll x2 = cur*2;
		if(x2 <= m) {
			q.push({x2, cnt+1});
		}

		ll a1 = cur*10+1;
		if(a1 <= m) {
			q.push({a1, cnt+1});
		}
	}

	if(ans == INF) {
		ans = -1;
	}
	else {
		ans += 1;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	bfs();
	cout << ans << "\n";
	
	return 0;
}