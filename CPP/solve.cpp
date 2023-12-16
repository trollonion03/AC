/**************************************************************
* CURRENT	: 	9019
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
#define MAXN 10001

int n;
int src, dst;
bool visited[MAXN];

void bfs() {
	queue<pair<int, string>> q;
	q.push({src, ""});
	visited[src] = true;

	while (!q.empty()) {
		int num = q.front().first;
		string log = q.front().second;
		q.pop();
		
		if (num == dst) {
			cout << log << "\n";
			break;
		}
		
		int d, s, l, r;
		
		d = (num*2) % 10000;
		if(!visited[d]) {
			q.push({d, log + "D"});
			visited[d] = true;
		}

		s = num-1 < 0 ? 9999 : num-1;
		if(!visited[s]) {
			q.push({s, log + "S"});
			visited[s] = true;
		}

		l = (num % 1000) * 10 + (num / 1000);
		if(!visited[l]) {
			q.push({l, log + "L"});
			visited[l] = true;
		}

		r = num / 10 + (num % 10)*1000;
		if(!visited[r]) {
			q.push({r, log + "R"});
			visited[r] = true;
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	while (n--) {
		cin >> src >> dst;
		memset(visited, 0, sizeof(visited));
		bfs();
	}
	return 0;
}