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
#define MAXV INT32_MAX

int n, input;
int left_max = 0;
int right_max = 0;
int total = 0;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> input;
		if(input == 1) left_max++;
		else left_max--;
		
		if(input == 2) right_max++;
		else right_max--;

		if(total < left_max || total < right_max)
			total = max(left_max, right_max);

		if (left_max < 0)
			left_max = 0;
		
		if (right_max < 0)
			right_max = 0;
	}

	cout << total << endl;

	return 0;
}