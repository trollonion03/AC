/**************************************************************
* CURRENT	: 	1931
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
int result;

typedef struct a {
	uint32_t s;
	uint32_t e;
} info;

bool cmp (info& a, info& b) {
	if (a.e < b.e)
		return true;
	else if (a.e == b.e)
		return (a.s < b.s);
	else
		return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	info array[MAXN];
	for(int i=0; i<n; i++) {
		cin >> array[i].s >> array[i].e;
	}

	sort(array, array+n, cmp);

	int cnt = 1;
	uint32_t tmp = array[0].e;

	for (int i=1; i<n; i++) {
		if(array[i].s < tmp) {
			continue;
		}
		else {
			tmp = array[i].e;
			cnt++;
		}
	}

	cout << cnt << endl;

	return 0;
}