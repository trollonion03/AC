/**************************************************************
* CURRENT	: 	25418
* NEXT 		: 	7569
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
#define MAXN 1000010

int n;
int src, dst;
bool visited[MAXN];

void bfs() {
	queue<pair<int, int>> q;
	q.push({src, 0});
	visited[src] = true;

	while (!q.empty()) {
		int num = q.front().first;
		int cnt = q.front().second;
		q.pop();
		
		if (num == dst) {
			cout << cnt << "\n";
			break;
		}
		
		int c1, c2;
		
		c1 = num+1;
		if(c1 <= MAXN && !visited[c1]) {
			visited[c1] = true;
			q.push({c1, cnt+1});
		}

		c2 = num * 2;
		if(c2 <= MAXN && !visited[c2]) {
			visited[c2] = true;
			q.push({c2, cnt+1});
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> src >> dst;
	bfs();
	return 0;
}