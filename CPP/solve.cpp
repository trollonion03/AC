/**************************************************************
* CURRENT	: 	3025
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
#include <deque>

using namespace std;
constexpr int INF = 0x3f3f3f3f;
typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int,int>
#define NOP ;
#define MAXN 30001

int r, c, n, s;
char a[MAXN][31];
vector<pair<int, int>> wall[31];
deque<pair<int, int>> q;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> r >> c;
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			cin >> a[i][j];
			if(a[i][j] == 'X') {
				//벽 정보 저장 (j열에 i번째줄)
				wall[j].push_back({i, 1});
				//1: 벽, 2: 돌
			}
		}
	}

	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> s;
		q.push_back({s-1, 0});
	}

	while(!q.empty()) {
		int st = q.front().first;
		int h = q.front().second;
		q.pop_front();
		

		//조건 1: 해당 열에 벽이 없는 경우
		if(wall[st].size() == 0) {
			a[r-1][st] = 'O';
			wall[st].push_back({r-1, 2});
			continue;
		}

		//벽이 or 돌이 존재하는 경우
		for(int i=0; i<wall[st].size(); i++) {
			int pos = wall[st][i].first;
			int check = wall[st][i].second;

			//벽의 y 좌표가 돌 보다 높으면 skip
			if(pos-1 < h) {
				if(i == wall[st].size()-1) {
					a[r-1][st] = 'O';
					wall[st].push_back({r-1, 2});
					break;
				}
				else {
					continue;
				}
			}

			// 조건 2: 아래가 벽일 경우
			if(check == 1) {
				a[pos-1][st] = 'O';
				//insert로 벽 좌표 위에 돌덩이 위치 기록(주의 필요)
				//vector로 중간 값 삽입 시 시간 복잡도가 O(N)이 된다.
				//container + list 조합으로 해결해야할듯 하다.
				wall[st].insert(wall[st].begin()+i, make_pair(pos-1, 2));
				break;
			}
			//조건 3: 아래가 돌덩이인 경우
			//queue->deque 이용
			//TODO: 돌의 y좌표 속성 추가 & 검사 구현
			if(check == 2) {
				//3.1. 왼쪽 검사&왼쪽 아래 검사
				if(st-1 >= 0 && a[pos-1][st-1] == '.' && a[pos][st-1] == '.') {
					q.push_front({st-1, pos});
					break;
				}

				//3.2. 오른쪽 검사&오른쪽 아래 검사
				if(st+1 < c && a[pos-1][st+1] == '.' && a[pos][st+1] == '.') {
					q.push_front({st+1, pos});
					break;
				}

				//3.3. 둘 다 아닌 경우
				a[pos-1][st] = 'O';
				wall[st].insert(wall[st].begin()+i, make_pair(pos-1, 2));
				break;
			}
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
