/**************************************************************
* CURRENT	: 	1406
* NEXT 		: 	7569
***************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>

using namespace std;
constexpr int INF = 0x3f3f3f3f;
typedef long long ll;
typedef unsigned long long ull;

#define NOP ;
#define MAXN 1000000

int n, tmp;
string cmd;

typedef struct Node {
	Node *prev;
	Node *next;
	char data;
};

class CDLinkedList {
public:
	Node *begin;
	Node *end;
	int size = 0;
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	CDLinkedList cdl;

	
    cin >> cmd;
    //TODO: begin, end 노드의 prev, next 포인터 지정 필요 -> nullptr로 판별;
    for(int i=0; i<cmd.size(); i++) {
        Node *n = new Node;
        n->data = cmd[i];
        if(i == 0) {
            cdl.begin = n;
        }
        else {
            cdl.end->next = n;
			n->prev = cdl.end;
        }
        cdl.end = n;
        cdl.size++;

    }
    
#if 0
    Node *tmp = cdl.begin;
    for(int i=0; i<cdl.size; i++) {
        cout << tmp->data;
        tmp = tmp->next;
    }
#endif

#if 1
    cin >> n;
    Node *cur = cdl.end;
    while(n--) {
        cin >> cmd;
        if(cmd == "L") {
            if(cur->prev)
				cur = cur->prev;
        }
        else if(cmd == "D") {
            if(cur->next)
				cur = cur->next;
        }
        else if(cmd == "B") {
			if (cur != nullptr) {
				Node *tmp = cur;
				cur = tmp->prev;
				if(tmp->next) {
					cur->next = tmp->next;
					tmp->next->prev = cur;
					tmp->prev=nullptr;
				}
				else {
					cur->next = nullptr;
					cdl.end = cur;
				}
				cdl.size--;
			}
        }
        else if(cmd == "P") {
			char ch;
			cin >> ch;
			Node* tmp = new Node;
			tmp->data = ch;
			tmp->prev = cur;
			if(cur->next) {
				tmp->next=cur->next;
				cur->next->prev=tmp;
			}
			else {
				tmp->next = nullptr;
				cdl.end = tmp;
			}
			cdl.size++;
        }
    }

	Node *tmp = cdl.begin;
    for(int i=0; i<cdl.size; i++) {
        cout << tmp->data;
        tmp = tmp->next;
    }
#endif

    // cin >> n;
	// for(int i=0; i<n; i++) {
	// 	cin >> cmd;
	// 	if(cmd == "push_front") {
	// 		cin >> tmp;
	// 		if(a.size == 0) {
	// 			Node *nw = new Node;
	// 			a.begin = nw; a.end = nw;
	// 			a.begin->data = tmp;
				
	// 			a.begin->next = 0;
	// 			a.begin->prev = 0;
	// 			a.size++;
	// 		}
	// 		else {
	// 			Node *nw = new Node;
	// 			nw->data = tmp;
				
	// 			nw->next = a.begin;
	// 			nw->prev = 0;
				
	// 			a.begin->prev = nw;
	// 			a.begin = nw;
	// 			a.size++;
	// 		}
	// 	}
	// 	else if(cmd == "push_back") {
	// 		cin >> tmp;
	// 		if(a.size == 0) {
	// 			Node *nw = new Node;
	// 			a.begin = nw; a.end = nw;
	// 			a.begin->data = tmp;
				
	// 			a.begin->next = 0;
	// 			a.begin->prev = 0;
	// 			a.size++;
	// 		}
	// 		else {
	// 			Node *nw = new Node;
	// 			nw->data = tmp;

	// 			a.end->next = nw;
	// 			nw->prev = a.end;
	// 			a.end = nw;
	// 			a.size++;
	// 		}
	// 	}
	// 	else if(cmd == "pop_front") {
	// 		if(a.size == 0) {
	// 			cout << -1 << endl;
	// 		}
	// 		else if(a.size == 1) {
	// 			cout << a.begin->data << endl;
	// 			delete a.begin;
	// 			a.begin = 0; a.end = 0;
	// 			a.size--;
	// 		}
	// 		else {
	// 			cout << a.begin->data << endl;
	// 			Node *nw = a.begin->next;
	// 			delete a.begin;
	// 			a.begin = nw;
	// 			a.begin->prev = 0;
	// 			a.size--;
	// 		}
	// 	}
	// 	else if(cmd == "pop_back") {
	// 		if(a.size == 0) {
	// 			cout << -1 << endl;
	// 		} 
	// 		else if(a.size == 1) {
	// 			cout << a.end->data << endl;
	// 			delete a.end;
	// 			a.begin = 0; a.end = 0;
	// 			a.size--;
	// 		}
	// 		else {
	// 			cout << a.end->data << endl;
	// 			Node *nw = a.end->prev;
	// 			delete a.end;
	// 			a.end = nw;
	// 			a.end->next = 0;
	// 			a.size--;
	// 		}
	// 	}
	// 	else if(cmd == "size") {
	// 		cout << a.size << endl;
	// 	}
	// 	else if(cmd == "empty") {
	// 		if(a.size > 0)
	// 			cout << 0 << endl;
	// 		else
	// 			cout << 1 << endl;
	// 	}
	// 	else if(cmd == "front") {
	// 		if(a.size <= 0) {
	// 			cout << -1 << endl;
	// 		}
	// 		else {
	// 			cout << a.begin->data << endl;
	// 		}

	// 	}
	// 	else if(cmd == "back") {
	// 		if(a.size <= 0) {
	// 			cout << -1 << endl;
	// 		}
	// 		else {
	// 			cout << a.end->data << endl;
	// 		}
	// 	}
	
	// }

	return 0;
}