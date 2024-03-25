/**************************************************************
* CURRENT	: 	9461
* NEXT 		: 	NULL
***************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <memory.h>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cmath>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;
constexpr int INF = 0x3f3f3f3f;
typedef long long ll;
typedef unsigned long long ull;

#define TEST 1
#define pii pair<int, int>
#define pip pair<int, pii>
#define plp pair<ll, pii>
#define pldp pair<long double, pii>
#define pdd pair<double, double>
#define pff pair<float, float>
#define NOP ;
#define MAXN 111

int t, n;
ll dp[MAXN];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i=1; i<=3; i++)
			dp[i] = 1;
		dp[4] = dp[5] = 2;
		for(int i=6; i<=n; i++) {
			dp[i] = dp[i-1] + dp[i-5];
		}
		cout << dp[n] << "\n";
	}
	return 0;
}