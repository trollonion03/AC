/**************************************************************
* CURRENT	: 	1966
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

int t, n, m, tmp, cnt = 0;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> t;
	for(int i=0; i<t; i++) {
		queue<pair<int,int>> q;
		priority_queue<int> pq;
		cin >> n >> m;
		for(int j=0; j<n; j++) {
			cin >> tmp;
			q.push({j, tmp});
			pq.push(tmp);
		}
		while(!q.empty()) {
			int loc = q.front().first;
			int val = q.front().second;
			q.pop();
			if(pq.top() == val) {
				pq.pop();
				cnt++;
				if(m == loc) {
					cout << cnt << endl;
					break;
				}
			}
			else {
				q.push({loc, val});
			}
		}
		cnt = 0;
	}
	return 0;
}