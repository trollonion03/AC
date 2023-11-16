/**************************************************************
* SOLVED	:	1
* CURRENT	: 	16496
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
long long result;
string input[101];

int cmp(string a, string b) {
	return a + b > b + a;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> input[i];
	}

	sort(input, input + n, cmp);

	string s_res = "";
	for (int j = 0; j < n; j++) {
		s_res += input[j];
	}

	cout << s_res << endl;

	return 0;
}