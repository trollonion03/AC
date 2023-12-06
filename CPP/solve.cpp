/**************************************************************
* CURRENT	: 	1260
* NEXT 		: 	15720
***************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>

using namespace std;
constexpr int INF = 0x3f3f3f3f;
typedef long long ll;
typedef unsigned long long ull;

#define NOP ;
#define MAXN 100000

int n, m, v;
int x, y;
bool visited[1001];
vector<int> vec[1001];

void dfs(int a) {
	visited[a] = true;
	cout << a << " ";

	for(int i=0; i<vec[a].size(); i++) {
		int tmp = vec[a][i];
		if(!visited[tmp]) {
			dfs(tmp);
		}
	}
}

void bfs(int a) {
	queue<int> q;
	q.push(a);
	visited[a] = true;
	cout << a << " ";

	while(!q.empty()) {
		int t = q.front();
		q.pop();
		for(int i=0; i<vec[t].size(); i++) {
			int tmp = vec[t][i];
			if(!visited[tmp]) {
				q.push(tmp);
				visited[tmp] = true;
				cout << tmp << " ";
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> v;
	for(int i=0; i<m; i++) {
		cin >> x >> y;
		vec[x].push_back(y);
		vec[y].push_back(x);
	}

	for(int i=0; i<n; i++) {
		sort(vec[i].begin(), vec[i].end());
	}
 
	dfs(v);
	cout << endl;
	memset(visited, false, sizeof(visited));
	bfs(v);
	cout << endl;
	
	return 0;
}