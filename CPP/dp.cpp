/**************************************************************
* CURRENT	: 	24416
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
#include <sstream>

using namespace std;
constexpr int INF = 0x3f3f3f3f;
typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int,int>
#define NOP ;
#define MAXN 41

int dp[MAXN];
int n, c1 = 0, c2 = 0;

int recursion(int n) {
    if(n == 1 || n == 2) {
        return 1;
    }
    else {
        c1++;
        return (recursion(n-1) + recursion(n-2));
    }
}

void dps(int n) {
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3; i<=n; i++) {
        c2++;
        dp[i] = dp[i-1] + dp[i-2];
    }
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    
    c1++;
    cin >> n;
    recursion(n);
    dps(n);
    cout << c1 << " " << c2 << "\n";

	return 0;
}
