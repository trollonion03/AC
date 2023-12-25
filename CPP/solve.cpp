/**************************************************************
* CURRENT	: 	5525
* NEXT 		: 	7569
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
#define MAXN 101

int n, m;
string a;
int ans = 0;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	cin >> a;
	for(int i=0; i<m; i++) {
		int k = 0;
		if(a[i] == 'O')
			continue;
		else {
			while(a[i+1] == 'O' && a[i + 2] == 'I') {
				k++;
				if(k == n) {
					k--;
					ans++;
				}
				i += 2;
			}
			k = 0;
		}
	}
	cout << ans << "\n";

	return 0;
}