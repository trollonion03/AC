/**************************************************************
* CURRENT	: 	1918
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
#include <stack>

using namespace std;
constexpr int INF = 0x3f3f3f3f;
typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int,int>
#define NOP ;
#define MAXN 51

string s;
stack<char> st;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> s;
	for(int i=0; i<s.size(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			cout << s[i];
			continue;
		}
		
		if(s[i] == '(') {
			st.push(s[i]);
		}
		else if(s[i] == ')') {
			while(!st.empty()) {
				if(st.top() != '(') {
					cout << st.top();
					st.pop();
					continue;
				}
				break;
			}
			st.pop();
		}
		else if(s[i] == '/' || s[i] == '*') {
			while(!st.empty()) {
				if(st.top() == '/' || st.top() == '*') {
					cout << st.top();
					st.pop();
					continue;
				}
				break;
			}
			st.push(s[i]);
		}
		else if(s[i] == '+' || s[i] == '-') {
			while(!st.empty()) {
				if(st.top() != '(') {
					cout << st.top();
					st.pop();
					continue;
				}
				break;
			}
			st.push(s[i]);
		}
	}

	while(!st.empty()) {
		cout << st.top();
		st.pop();
	} 
	cout << "\n";

	return 0;
}
