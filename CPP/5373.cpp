/**************************************************************
* CURRENT	: 	5373
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
#include <queue>
#include <sstream>

using namespace std;
constexpr int INF = 0x3f3f3f3f;
typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int,int>
#define NOP ;
#define MAXN 9

//https://rubiks-cube-solver.com/fr/
typedef struct cube {
	char shape[3][3];
};

typedef struct inst {
	int shape;		// 면
	int pos;  		// 행 or 열
	int type; 		// 1: 세로, 2: 가로
	int rev;
};

enum CUBE_SHAPE {U, D, F, B, L, R};

cube *CUBE[6]; // U, D, F, B, L, R
int n, tc;
string cmd, tmp;
/*
W 위(U), G 왼(L), R 앞(F), Y 아래(D), B 오(R), O 뒤(B) 
      O O O
      O O O
      O O O
G G G Y Y Y B B B W W W
G G G Y Y Y B B B W W W
G G G Y Y Y B B B W W W
      R R R
      R R R
      R R R
*/

void process(queue<inst> *q) {
	char tmp[4];
	inst first = q->front();
	
	while(!q->empty()) {
		int cShape = q->front().shape;
		int cPos = q->front().pos;
		int cType = q->front().type;
		q->pop();
		//next shape
		int nShape = q->front().shape;
		int nPos = q->front().pos;
		int nType = q->front().type;

		//TODO: U의 경우부터 구현
		//다음 면의 색 저장
		for(int i=0; i<3; i++) {
			if(cType == 1) {
				tmp[i] = CUBE[nShape]->shape[i][nPos];
			}
			else if(cType == 2) {
				tmp[i] = CUBE[nShape]->shape[nPos][i];
			}
		}


	}
}


//면 회전에 대해서도 구현해야함
void rotateCube(string cmd) {
	queue<inst> q;
	if(cmd[0] == 'U') {
		if(cmd[1] == '+') {
			//B1_->L1|->F3_->R3|
			q.push({B, 1, 2, 0});
			q.push({L, 1, 1, 0});
			q.push({F, 3, 2, 0});
			q.push({R, 3, 1, 0});
			process(&q);
		}
		else if(cmd[1] == '-') {
			//R3|->F3_->L1|->B1_
			q.push({R, 3, 1, 0});
			q.push({F, 3, 2, 0});
			q.push({L, 1, 1, 0});
			q.push({B, 1, 2, 0});
			process(&q);
		}
	}
	else if(cmd[0] == 'D') {
		if(cmd[1] == '+') {

			

		}
		else if(cmd[1] == '-') {


		}
	}
	else if(cmd[0] == 'F') {
		if(cmd[1] == '+') {

			

		}
		else if(cmd[1] == '-') {


		}
	}
	else if(cmd[0] == 'B') {
		if(cmd[1] == '+') {

			

		}
		else if(cmd[1] == '-') {


		}
	}
	else if(cmd[0] == 'L') {
		if(cmd[1] == '+') {

			

		}
		else if(cmd[1] == '-') {


		}
	}
	else if(cmd[0] == 'R') {
		if(cmd[1] == '+') {

			

		}
		else if(cmd[1] == '-') {


		}
	}
}

void initCube(cube *tgt, int flag) {
	char ch;
	switch(flag) {
	case 0:
		ch = 'w';
		break;
	case 1:
		ch = 'y';
		break;
	case 2:
		ch = 'r';
		break;
	case 3:
		ch = 'o';
		break;
	case 4:
		ch = 'g';
		break;
	case 5:
		ch = 'b';
		break;
	default:
		break;
	}

	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) {
			tgt->shape[i][j] = ch;
		}
	}
}

void init() {
	for(int i=0; i<6; i++) {
		CUBE[i] = new cube;
		initCube(CUBE[i], i);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	init();
	cin >> tc;
	for(int i=0; i<tc; i++) {
		cin >> n;
		for(int j=0; j<n; j++) {
			cin >> cmd;
			rotateCube(cmd);
		}
	}
	return 0;
}
