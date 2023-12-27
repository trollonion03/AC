/**************************************************************
* CURRENT	: 	1167
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
#include <stack>

using namespace std;
constexpr int INF = 0x3f3f3f3f;
typedef long long ll;
typedef unsigned long long ull;

#define NOP ;
#define MAXN 100001

typedef struct tp {
	int x;
	int dist;
};

int n, na, nb, dst, mxn;
int ans = -1;
bool visited[MAXN];
stack<tp> st;
vector<pair<int,int>> a[MAXN];

int dfs(int start) {
	int an = -1;
	st.push({start, 0});
	visited[start] = true;

	while(!st.empty()) {
		int cur = st.top().x;
		int dist = st.top().dist;
		st.pop();
		
		if(an < dist) {
			an = dist;
			mxn = cur;
		}

		for(int i=0; i<a[cur].size(); i++) {
			int next = a[cur][i].first;
			int ndst = a[cur][i].second;

			if(!visited[next]) {
				st.push({next, dist+ndst});
				visited[next] = true;
			}
		}
	}
	return an;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> na;
		while(1) {
			cin >> nb;
			if(nb == -1) break;
			cin >> dst;
			a[na].push_back({nb, dst});
			a[nb].push_back({na, dst});
		}
	}

	dfs(1);
	memset(visited, 0, sizeof(visited));
	ans = dfs(mxn);
	cout << ans << "\n";
	
	return 0;
}