/**************************************************************
* CURRENT	: 	11725
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

int n, m;
int visited[MAXN];
vector<int> a[MAXN];
stack<int> st;

void dfs() {
	st.push(1);
	
	while(!st.empty()) {
		int x = st.top();
		st.pop();

		for(int i=0; i<a[x].size(); i++) {
			if(visited[a[x][i]] == 0) {
				visited[a[x][i]] = x;
				st.push(a[x][i]);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for(int i=0; i<n; i++) {
		int aa, b;
		cin >> aa >> b;
		a[aa].push_back(b);
		a[b].push_back(aa);
	}

	dfs();

	for(int i=2; i<=n; i++) {
		cout << visited[i] << '\n';
	}

	return 0;
}
