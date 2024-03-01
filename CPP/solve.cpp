/**************************************************************
* CURRENT	: 	17490
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
#define MAXN 1000002

int n, m;
ll k, ans;
int u, v;
int p[MAXN];
bool cut[MAXN];
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
	for(int i=2; i<=n; i++) {
		if(find_r(i) != find_r(1)) {
			return false;
		}
	}
	return true;
}

void union_r(int x, int y) {
	x = find_r(x);
	y = find_r(y);

	if(x == 0 || (x == n && y == 1)) {
		p[x] = y;
		return;
	}
	
	if(x < y) 
		p[y] = x;
	else
		p[x] = y;
}

ll kruskal() {
	ll rtn = 0;
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

	cin >> n >> m >> k;
	if(m <= 1) {
		cout << "YES\n";
		return 0;
	}
	init(n);
	for(int i=1; i<=n; i++) {
		cin >> u;
		a.push_back({u, {0, i}}); //와우도를 0번 노드로 지정
	}

	for(int i=0; i<n; i++) {
		cin >> u >> v;

		//강의실이 원형으로 되어있음을 고려
		if(u == n && v == 1) {
			cut[u] = true;
			continue;
		}
		else if(u == 1 && v == n) {
			cut[v] = true;
			continue;
		}

		if(u<v)
			cut[u] = true;
		else
			cut[v] = true;
		
	}
	for(int i=1; i<n; i++) {
		if(!cut[i]) {
			union_r(i, i+1);
		}
	}

	// n번째 노드와 1번째 노드를 연결
	// 만약에 공사중이면 제외
	if(!cut[n])
		union_r(n, 1);

	if(!isGraph()) {
		sort(a.begin(), a.end());
		ans = kruskal();
		//다리 가설 이후 모든 노드가 연결되었는지 확인
		if(ans <= k && isGraph()) {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";

	return 0;
}
