/**************************************************************
* ARCHIVE	: 	3025
* First try :   2024.01.07
* Latest try:   2024.01.10
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
#include <set>
#include <deque>

using namespace std;
constexpr int INF = 0x3f3f3f3f;
typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int,int>
#define NOP ;
#define MAXN 30001

typedef struct f {
	int start;
	int y; 
	int x;
};

int r, c, n, s;
char a[MAXN][31];
set<int> wall[31];
stack<pair<int, int>> q[31];

// 시작 열, y좌표, x좌표
void roll(int sp, int sy, int sx) {
	//재귀 함수로 구현시 디버깅이 어려움으로, stack를 사용하여 구현
	stack<f> stk;
	stk.push({sp, sy, sx});
	
	while(!stk.empty()) {
		int x = stk.top().x;
		int y = stk.top().y;
		int start = stk.top().start;
		int w = *(wall[x].upper_bound(y));
		stk.pop();

		//벽 위에 떨어진 경우
		if(a[w][x] == 'X') {
			a[w-1][x] = 'O';
			wall[x].insert(w-1);
			wall[x].erase(w);
			continue;
		}
		
		//돌 위에 떨어진 경우
		if(a[w][x] == 'O') {
			if(x-1>=0 && a[w-1][x-1] == '.' && a[w][x-1] == '.') {
				q[start].push({w-1, x});
				stk.push({start, w-1, x-1});
				continue;
			}
			if(x+1<c && a[w-1][x+1] == '.' && a[w][x+1] == '.') {
				q[start].push({w-1, x});
				stk.push({start, w-1, x+1});
				continue;
			}
			else {
				a[w-1][x] = 'O';
				wall[x].erase(w);
				wall[x].insert(w-1);
				continue;
			}
		}
	}
	
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> r >> c;
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			cin >> a[i][j];
			if(a[i][j] == 'X') {
				//벽 정보 저장 (j열에 i번째줄)
				wall[j].insert(i);
			}
		}
	}

	for(int i=0; i<c; i++) {
		wall[i].insert(r);
		a[r][i] = 'X';
	}

	cin >> n;
	int cx, cy;
	for(int i=0; i<n; i++) {
		cin >> s;
		s--;
		
		while(!q[s].empty()) {
			cy = q[s].top().first;
			cx = q[s].top().second;

			if(a[cy][cx] == '.') {
				break;
			}
			q[s].pop();

		}
		if(q[s].empty()) {
			roll(s, 0, s);
		}
		else {
			roll(s, cy, cx);
		}
		
	}

	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			cout << a[i][j];
		}
		cout << "\n";
	}

	return 0;
}

//반례는 다 맞는데 시간초과가 난다라,,,
//솔루션 참고 - https://hillier.tistory.com/118 - 해당 솔루션의 로직을 일부 참고하였습니다.
//일일이 돌이 떨어지는 위치를 탐색하게 된다면 벽이 매우 많은 경우 탐색 시간이
//증가하기에 시간 초과가 발생하게 된다.
//Stack을 이용해서 먼저 떨어지는 돌에 대한 체크포인트(바로가기)를 설정한 후
//체크포인트에 장애물(벽 or 돌)이 존재한다면 해당 체크포인트를 제거하고
//새로 탐색하는 방식으로 문제를 해결해야 시간 초과를 피할 수 있다.
