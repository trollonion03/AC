/**************************************************************
* CURRENT	: 	1158
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
#include <queue>

using namespace std;
constexpr int INF = 0x3f3f3f3f;
typedef long long ll;
typedef unsigned long long ull;

#define NOP ;
#define MAXN 100001

int n, k;
queue<int> q;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;
	for(int i=1; i<=n; i++) {
		q.push(i);
	}

	cout << "<";
	while (q.size()>1) {
		for(int i=0; i<k-1;i++) {
			int tmp = q.front();
			q.pop();
			q.push(tmp);
		}
		int ans = q.front();
		q.pop();
		cout << ans << ", ";
	}
	cout << q.front() << ">\n";
	
	return 0;
}