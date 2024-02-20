/**************************************************************
* CURRENT	: 	2162
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
#include <map>
#include <vector>
#include <queue>

using namespace std;
constexpr int INF = 0x3f3f3f3f;
typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int, int>
#define pip pair<int, pii>
#define NOP ;
#define MAXN 3001

typedef struct pos {
	double x;
	double y;
};

pos p1, p2, p3, p4;
int n;
int x1, y1, x2, y2;
int p[MAXN];
bool ans;
vector<int> a[MAXN];
vector<pos> g1;
vector<pos> g2;
queue<int> q;
bool visited[MAXN];
int ans1 = 0, ans2 = -1;

void init(int x) {
	for(int i=0; i<=n; i++) {
		p[i] = i;
	}
}

int ccw(pos p1, pos p2, pos p3) {
	double tmp = (p2.x-p1.x) * (p3.y-p1.y) - (p3.x-p1.x) * (p2.y - p1.y);
	if(tmp > 0)
		return 1;
	if(tmp < 0)
		return -1;
	return 0;
}

int find_r(int x) {
	if(p[x] == x)
		return x;
	return p[x] = find_r(p[x]);
}

bool union_r(int x, int y) {
	x = find_r(x);
	y = find_r(y);

	if(x != y) {
		p[x] = y;

		a[x].push_back(y);
		a[y].push_back(x);
		return true;
	}
	return false;
}

bool checkLine(int a, int b, int c, int d) {
	if(a > b)
		swap(a, b);
	if(c > d)
		swap(c, d);
	bool n = a<=d && b>=c;
	bool m = c<=b && d>=a;
	return n || m;
}

bool check(pos p1, pos p2, pos p3, pos p4) { 
	int t1 = ccw(p1, p2, p3);
	int t2 = ccw(p1, p2, p4);
	int t3 = ccw(p3, p4, p1);
	int t4 = ccw(p3, p4, p2);

	if(t1*t2 == 0 && t3*t4 == 0) {
		return  checkLine(p1.x, p2.x, p3.x, p4.x) && checkLine(p1.y, p2.y, p3.y, p4.y);
	}
	else {
		return (t1*t2<=0) && (t3*t4<=0);
	}
}

int bfs(int x) {
	int tmp = 1;
	q.push(x);
	visited[x] = true;

	while(!q.empty()) {
		int cur = q.front();
		q.pop();

		for(int i=0; i<a[cur].size(); i++) {
			if(!visited[a[cur][i]]) {
				tmp++;
				q.push(a[cur][i]);
				visited[a[cur][i]] = true;
			}
		}
	}
	return tmp;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	init(n);
	for(int i=0; i<n; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		g1.push_back({(double)x1, (double)y1});
		g2.push_back({(double)x2, (double)y2});
	}

	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(check(g1[i], g2[i], g1[j], g2[j])) {
				union_r(i, j);
			}
		}
	}

	for(int i=0; i<n; i++) {
		if(!visited[i])	{
			ans1++;
			ans2 = max(ans2, bfs(i));
		}
	}

	cout << ans1 << "\n" << ans2 << "\n"; 

	return 0;
}
