/**************************************************************
* CURRENT	: 	1464
* NEXT 		: 	NULL
***************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <memory.h>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cmath>
#include <unordered_map>
#include <vector>
#include <deque>

using namespace std;
constexpr int INF = 0x3f3f3f3f;
typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int, int>
#define pip pair<int, pii>
#define plp pair<ll, pii>
#define pldp pair<long double, pii>
#define pdd pair<double, double>
#define pff pair<float, float>
#define NOP ;
#define MAXN 2001

string str;
deque<char> a;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
        char n = str[i];
        if (a.empty()) {
            a.push_back(n);
        }
        else if (a.back() <= n) {
            a.push_back(n);
        }
        else if (a.front() >= n) {
            a.push_front(n);
        }
        else {
            a.push_back(n);
        }
    }

	while(!a.empty()) {
		cout << a.front();
		a.pop_front();
	}
	cout << "\n";

	return 0;
}
