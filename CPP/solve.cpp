/**************************************************************
* CURRENT	: 	2810
* NEXT 		: 	15720
***************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cstring>
#include <string>
#include <vector>

using namespace std;
constexpr int INF = 0x3f3f3f3f;
typedef long long ll;
typedef unsigned long long ull;

#define NOP ;
#define MAXN 100000

int n;
char c;
bool flag;
double sum;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> c;
		if (c == 'S') sum++;
		else //(c == 'L')
		{
			flag = true;
			sum += 0.5;
		}	
	}
	
	if (flag) cout << sum + 1;
	else cout << sum;
	return 0;
}