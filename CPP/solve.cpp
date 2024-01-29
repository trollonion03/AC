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
#include <deque>
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

enum CUBE_SHAPE {U, D, F, B, L, R};

cube *CUBE[6]; // U, D, F, B, L, R
deque<string> tmps[6];
int n, tc;
string cmd, tmp;
/*
W 위, G 왼, R 앞, Y 아래, B 오, G 왼 
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

void rotateCube(string cmd) {
	if(cmd[0] == 'U') {
		if(cmd[1] == '+') {

			

		}
		else if(cmd[1] == '-') {


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
