/**************************************************************
* CURRENT	: 	1904
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

int n;
ll tmp;
vector<ll> vec;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    
    for(int i=0; i<3; i++) {
		vec.push_back(i);
	}
	cin >> n;
	for(int i=3; i<=n; i++) {
		tmp = vec[i-1] + vec[i-2];
		vec.push_back(tmp%15746); 
	}
	cout << vec[n] % 15746 << "\n";

	return 0;
}
