/**************************************************************
* CURRENT	: 	24479
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
#include <stack>
#include <vector>

using namespace std;
constexpr int INF = 0x3f3f3f3f;
typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int,int>
#define NOP ;
#define MAXN 100100


int n, m, s;
int t1, t2;
bool visited[MAXN];
vector<int> a[MAXN];
int result[MAXN] = { 0, };
int cnt = 0;


void dfs(int x) {
	visited[x] = true;
	cnt++;
	result[x] = cnt;

	for(int i=0; i<a[x].size(); i++) {
		if(!visited[a[x][i]]) {
			dfs(a[x][i]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m >> s;
	for(int i=1; i<=m; i++) {
		cin >> t1 >> t2;
		a[t1].push_back(t2);
		a[t2].push_back(t1);
	}

	for(int i=1; i<=n; i++) {
		sort(a[i].begin(), a[i].end());
	}

	dfs(s);
	for(int i=1; i<=n; i++) {
		cout << result[i] << "\n"; 
	}
}
