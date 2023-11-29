/**************************************************************
* CURRENT	: 	1012
* NEXT 		: 	15720
***************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;
constexpr int INF = 0x3f3f3f3f;
typedef long long ll;
typedef unsigned long long ull;

#define NOP ;
#define MAXN 100000

bool visited[51][51];
bool a[51][51];

int cnt = 0;
int n, m, c, t;


void dfs(int y, int x) {
	visited[x] = true; 
	cout << x << " ";
	for(int i=0; i<graph[x].size(); i++) { //인접 노드 탐색
		int y = graph[x][i];
		if(!visited[y])	{	//방문하지 않으면, 해당 노드에 대한 탐색 시작
			dfs(y); //재귀적 방문
			cnt++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> t;
	cin >> n >> m >> c;
	for(int i=0; i<t; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(b);
	}

	dfs(1); //최초 노드 방문
	printf("%d\n", cnt);
	
	return 0;
}