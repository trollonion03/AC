/**************************************************************
* CURRENT	: 	2578
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
#define MAXN 26

int input;
int cnt = 0;
int a[MAXN][MAXN];
bool visited[MAXN][MAXN];
vector<pair<int,int>> vec[MAXN];
bool xc[6];
bool yc[6];
bool d1f = false, d2f = false;
int bcnt=0;

bool check(int x) {
	int posx = vec[x][0].first;
	int posy = vec[x][0].second;

	if(visited[posx][posy]) {
		return false;
	}

	visited[posx][posy] = true;
	
	int xcnt = 0;
	int ycnt = 0;
	int d1 = 0;
	int d2 = 0;
	for(int i=0; i<5; i++) {
		if(!xc[posx]) {	
			if(visited[posx][i]) {
				xcnt++;
				if(xcnt == 5) {
					bcnt++;
					xc[posx] = true;
					if(bcnt == 3)
						return true;
				}
			}
		}
		if(!yc[posy]) {
			if(visited[i][posy]) {
				ycnt++;
				if(ycnt == 5) {
					bcnt++;
					yc[posy] = true;
					if(bcnt == 3)
						return true;
				}
			}
		}
		if(!d1f) {
			if(visited[i][i]) {
				d1++;
				if(d1 == 5) {
					bcnt++;
					d1f = true;
					if(bcnt == 3)
						return true;
				}
			}
		}
		if(!d2f) {
			if(visited[i][4-i]) {
				d2++;
				if(d2 == 5) {
					bcnt++;
					d2f = true;
					if(bcnt == 3)
						return true;
				}
			}
		}	
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for(int i=0; i<5; i++) {
		for(int j=0; j<5; j++) {
			cin >> a[i][j];
			vec[a[i][j]].push_back({i, j});
		}
	}

	for(int i=0; i<5; i++) {
		for(int j=0; j<5; j++) {
			cin >> input;
			bool isBingo = check(input);
			cnt++;
			if(isBingo) {
				cout << cnt << "\n";
			}
		}
	}
	
	return 0;
}