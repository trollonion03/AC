/**************************************************************
* CURRENT	: 	2845
* NEXT 		: 	NULL
***************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <stack>

using namespace std;
constexpr int INF = 0x3f3f3f3f;
typedef long long ll;
typedef unsigned long long ull;

#define NOP ;
#define MAXN 100001

int l, p, tmp;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> l >> p;
	for(int i=0; i<5; i++) {
		cin >> tmp;
		cout << tmp - l * p << " ";
	}
	cout << endl;
	
	return 0;
}