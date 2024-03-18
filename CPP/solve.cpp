/**************************************************************
* CURRENT	: 	9095
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
#define MAXN 12

int t, n;
int dp[MAXN];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> t;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for(int i=4; i<12; i++) {
		dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
	}

	while(t--) {
		cin >> n;
		cout << dp[n] << "\n";	
 	}
	
	return 0;
}