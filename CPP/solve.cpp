/**************************************************************
* CURRENT	: 	1068
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
#include <stack>

using namespace std;
constexpr int INF = 0x3f3f3f3f;
typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int,int>
#define NOP ;
#define MAXN 51

int n, tmp, del, root;
int ans = 0;
stack<int> st;
vector<int> a[MAXN];

void dfs() {
	st.push(root);

	while(!st.empty()) {
		int x = st.top();
		st.pop();

		if(a[x].size() == 0) {
			ans++;
			continue;
		}

		int cnt = a[x].size();
		for(int i=0; i<a[x].size(); i++) {
		
			if(a[x][i] == del) {
				if(cnt-1 == 0) {
					cnt-=1;
					ans++;
				}
				continue;
			}
			st.push(a[x][i]);

		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> tmp;
		if(tmp == -1)
			root = i;
		else 
			a[tmp].push_back(i);
	}

	cin >> del;
	if(root == del)
		cout << 0 << "\n";
	else {
		dfs();
		cout << ans << "\n";
	} 

	
	return 0;
}
