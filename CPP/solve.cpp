/**************************************************************
* CURRENT	: 	15654
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
#include <queue>

using namespace std;
constexpr int INF = 0x3f3f3f3f;
typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int,int>
#define NOP ;
#define MAXN 9

int n, m;
int a[MAXN];
int b[MAXN];
int visited[MAXN];

void find(int l) {
	if(l == m) {
		for(int i=0; i<m; i++) {
			cout << a[i] << " ";
		}
		cout << "\n";
		return;
	}

	for(int i=0; i<n; i++) {
		if (!visited[i]) {
			a[l] = b[i];
			visited[i] = true;
			find(l+1);
			visited[i] = false;
		}
	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		cin >> b[i];
	}

	sort(b, b+n);
	find(0);

	return 0;
}
