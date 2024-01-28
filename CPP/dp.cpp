/**************************************************************
* CURRENT	: 	9184
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
#define MAXN 50

int dp[MAXN][MAXN][MAXN];
int a, b, c;

int w(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0) 
        return 1;
	else if (a > 20 || b > 20 || c > 20) 
		return w(20, 20, 20);
	else if (a < b && b < c) {
		if (dp[a][b][c] != 0) 
            return dp[a][b][c];
		else return dp[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
	}
	else {
		if (dp[a][b][c] != 0) 
            return dp[a][b][c];
		else return dp[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    memset(dp, 0, sizeof(dp));
    
    for(;;) {
        cin >> a >> b >> c;
        if(a == -1 && b == -1 && c == -1) {
            break;
        }
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << "\n";
    }

	return 0;
}
