/**************************************************************
* bfs implementation
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

bool visited[9]; 			//방문 여부 저장
vector<int> graph[9]; 		//vector 배열 생성(인접 노드에 대한 정보 저장)

int bfs(int start) {
	queue<int> q;
	q.push(start); // 첫 노드를 queue에 삽입
	visited[start] = true; //첫 노드 방문 처리

	while(!q.empty()) {
		int x = q.front(); //queue에 등록된 노드를 뽑아서 탐색 대상으로 지정
		q.pop();
		cout << x << endl;
		for(int i=0; i< graph[x].size(); i++) { //인접 노드 확인
			int y = graph[x][i];
			if(!visited[y]) { //인접 노드 중 방문하지 않은 노드 확인
				q.push(y); //노드 탐색 등록
				visited[y] = true;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	graph[1].push_back(2);
	graph[2].push_back(3);
	graph[3].push_back(8);

	graph[2].push_back(1);
    graph[2].push_back(7);

    graph[3].push_back(1);
    graph[3].push_back(4);
    graph[3].push_back(5);

    graph[4].push_back(3);
    graph[4].push_back(5);

    graph[5].push_back(3);
    graph[5].push_back(4);

    graph[6].push_back(7);

    graph[7].push_back(2);
    graph[7].push_back(6);
    graph[7].push_back(8);

    graph[8].push_back(1);
    graph[8].push_back(7);

	bfs(1); //최초 노드 방문
	
	return 0;
}