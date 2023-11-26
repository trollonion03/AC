/**************************************************************
* CURRENT	: 	2606
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

int n, k, m;
int x, y, g;
bool isy, isp;

int dig(int a) {
	if (a >= 0 && a <= 9) {
		return a;
	}
	
	int sum = 0;
	while(a > 0) {
		sum += x%10;
	}
	return dig(sum);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> k >> m;
		
		x = y = 0; g = 1;
		isy = isp = true;
		for(int j=1; j<=k; j++) {
			int tmp = dig(g);
			g *= m;
			if(isy && isp) {
				y += tmp;
				isy = false;
				isp = true;
			}
			else if(!isy && isp) {
				x += tmp;
				isy = true;
				isp = false;
			}
			else if(isy && !isp) {
				y -= tmp;
				isy = false;
				isp = false;
			}
			else if(!isy && !isp) {
				x -= tmp;
				isy = true;
				isp = true;
			}
			cout << x << " " << y << endl;
		}
	}

	return 0;
}