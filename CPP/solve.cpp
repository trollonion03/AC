/**************************************************************
* CURRENT	: 	1202
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
#define MAXN 300001

int n, k, cap = 0;
priority_queue<int, vector<int>, less<int>> pq;
vector<int> bag;
vector<pii> tgt;
ll ans = 0;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;
	for(int i=0; i<n; i++) {
		int a, b;
		cin >> a >> b;
		tgt.push_back({a, b});
	}

	for(int i=0; i<k; i++) {
		int a;
		cin >> a;
		bag.push_back(a);
	}

	sort(tgt.begin(), tgt.end());
	sort(bag.begin(), bag.end());

	for(int i=0; i<bag.size(); i++) {
		while(cap < n && tgt[cap].first <= bag[i]) {
			pq.push(tgt[cap].second);
			cap++;
		}
		if(!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
	}

	cout << ans << "\n";

	return 0;
}
