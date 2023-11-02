/**************************************************************
* SOLVED	:	1
* CURRENT	: 	10769
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

string str;
int cmp;
bool flag = false;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> str;
	for(int i=0; i < str.size(); i++) {
		if(str.substr(i, 3) == ":-)") {
			if(!flag) flag = true;
			cmp++;
			i += 2;
		}
		else if(str.substr(i, 3) == ":-(") {
			if(!flag) flag = true;
			cmp--;
			i += 2;
		}
	}

	if(flag) {
		if(cmp > 0) cout << "happy";
		else if(cmp < 0) cout << "sad";
		else if(cmp == 0) cout << "unsure";
	}
	else {
		cout << "none";
	}

	cout << "\n";

	return 0;
}