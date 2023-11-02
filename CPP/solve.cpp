/**************************************************************
* SOLVED	:	1
* CURRENT	: 	15881(clear)
* NEXT 		: 	15720
***************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cstring>
#include <string>

using namespace std;
constexpr int INF = 0x3f3f3f3f;
typedef long long ll;
typedef unsigned long long ull;

#define NOP ;
#define MAXN 100000

int n;
int cnt = 0;
string input;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> input;
	for(int i=0; i<n; i++) {
		if(input.substr(i, 4) == "pPAp") {
			cnt++;
			i += 3;
		}
	}

	cout << cnt << endl;

	return 0;
}