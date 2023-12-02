/**************************************************************
* CURRENT	: 	10866
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

int n, tmp;
string cmd;

typedef struct Node {
	Node *prev;
	Node *next;
	int data;
};

class CDeque {
public:
	Node *begin;
	Node *end;
	int size = 0;
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	CDeque a;

	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> cmd;
		if(cmd == "push_front") {
			cin >> tmp;
			if(a.size == 0) {
				Node *nw = new Node;
				a.begin = nw; a.end = nw;
				a.begin->data = tmp;
				
				a.begin->next = 0;
				a.begin->prev = 0;
				a.size++;
			}
			else {
				Node *nw = new Node;
				nw->data = tmp;
				
				nw->next = a.begin;
				nw->prev = 0;
				
				a.begin->prev = nw;
				a.begin = nw;
				a.size++;
			}
		}
		else if(cmd == "push_back") {
			cin >> tmp;
			if(a.size == 0) {
				Node *nw = new Node;
				a.begin = nw; a.end = nw;
				a.begin->data = tmp;
				
				a.begin->next = 0;
				a.begin->prev = 0;
				a.size++;
			}
			else {
				Node *nw = new Node;
				nw->data = tmp;

				a.end->next = nw;
				nw->prev = a.end;
				a.end = nw;
				a.size++;
			}
		}
		else if(cmd == "pop_front") {
			if(a.size == 0) {
				cout << -1 << endl;
			}
			else if(a.size == 1) {
				cout << a.begin->data << endl;
				delete a.begin;
				a.begin = 0; a.end = 0;
				a.size--;
			}
			else {
				cout << a.begin->data << endl;
				Node *nw = a.begin->next;
				delete a.begin;
				a.begin = nw;
				a.begin->prev = 0;
				a.size--;
			}
		}
		else if(cmd == "pop_back") {
			if(a.size == 0) {
				cout << -1 << endl;
			} 
			else if(a.size == 1) {
				cout << a.end->data << endl;
				delete a.end;
				a.begin = 0; a.end = 0;
				a.size--;
			}
			else {
				cout << a.end->data << endl;
				Node *nw = a.end->prev;
				delete a.end;
				a.end = nw;
				a.end->next = 0;
				a.size--;
			}
		}
		else if(cmd == "size") {
			cout << a.size << endl;
		}
		else if(cmd == "empty") {
			if(a.size > 0)
				cout << 0 << endl;
			else
				cout << 1 << endl;
		}
		else if(cmd == "front") {
			if(a.size <= 0) {
				cout << -1 << endl;
			}
			else {
				cout << a.begin->data << endl;
			}

		}
		else if(cmd == "back") {
			if(a.size <= 0) {
				cout << -1 << endl;
			}
			else {
				cout << a.end->data << endl;
			}
		}
	
	}

	return 0;
}