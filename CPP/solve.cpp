/**************************************************************
* CURRENT	: 	1240
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
#define MAXN 1001

int n, m;
stack<pii> st;
vector<pii> a[MAXN];
bool visited[MAXN];

void dfs(int s, int e) {
	st.push({s, 0});
	visited[s] = true;

	while(!st.empty()) {
		int x = st.top().first;
		int dist = st.top().second;
		st.pop();

		if(x == e) {
			cout << dist << "\n";
		}
		
		for(int i=0; i<a[x].size(); i++) {
			if(!visited[a[x][i].first]) {
				st.push({a[x][i].first, dist+a[x][i].second});
				visited[a[x][i].first] = true;
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for(int i=0; i<n-1; i++) {
		int aa, b, c;
		cin >> aa >> b >> c;
		a[aa].push_back({b, c});
		a[b].push_back({aa, c});
	}

	for(int i=0; i<m; i++) {
		int start, end;
		cin >> start >> end;
		dfs(start, end);
		memset(visited, 0, sizeof(visited));
	}
	
	return 0;
}
