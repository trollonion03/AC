/**************************************************************
* CURRENT	: 	2406
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

#define TEST 1
#define pii pair<int, int>
#define pip pair<int, pii>
#define plp pair<ll, pii>
#define pldp pair<long double, pii>
#define pdd pair<double, double>
#define pff pair<float, float>
#define NOP ;
#define MAXN 1001

int n, m;
int u, v;
int t = 0;
int p[MAXN];
#if TEST
unordered_map<int, int> con;
#else
bool con[MAXN][MAXN];
#endif
vector<pip> a;
vector<pii> ans;

void init(size_t size) {
	for(int i=0; i<=size+1; i++) {
		p[i] = i;
	}
}

ll getDist(pii p1, pii p2) {
	return pow(p1.first-p2.first, 2) + pow(p1.second-p2.second, 2);
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
        ans.push_back({x, y});
		rtn += cur.first;
        if(isGraph())
            break;
	}
	return rtn;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
    init(n);
    for(int i=0; i<m; i++) {
        cin >> u >> v;
#if TEST
        con.insert({u, v});
        con.insert({v, u});
#else
        con[u][v] = 1;
        con[v][u] = 1;
#endif
        union_r(u, v);
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> u;
            if(i==1||j==1) 
                continue;
#if TEST
            if(con.find(i) != con.end() && con[i] == j) {
                continue;
            }
            if(con.find(j) != con.end() && con[j] == i) {
                continue;
            }
#else
            if(con[i][j])
                continue;
#endif
            if(find_r(i) != find_r(j)) {
                a.push_back({u, {i, j}});
                // cout << u << " " << i << " " << j << endl;
            }
        }
    }

    sort(a.begin(), a.end());
    int cst = kruskal();
    cout << cst << " " << ans.size() << "\n";
    for(int i=0; i<ans.size(); i++) {
        cout << ans[i].second << " " << ans[i].first << "\n";
    }
	return 0;
}