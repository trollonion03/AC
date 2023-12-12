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
#define MAXN 101

typedef struct types {
        int x;
        int y;
        int z;
        int cnt;
}types;

bool visited[MAXN][MAXN][MAXN];
int box[MAXN][MAXN][MAXN];
int moveX[6] = {1, -1, 0, 0, 0, 0};
int moveY[6] = {0, 0, 1, -1, 0, 0};
int moveZ[6] = {0, 0, 0, 0, 1, -1};
int M, N, Z;       //가로, 세로

queue<types> bfs;

int main(void) 
{
        ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

        int cnt = 0;
        cin >> M >> N >> Z;
        for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                        for(int k=0; k<Z; k++) {
                                cin >> box[i][j][k];
                                if (box[i][j][k] == 1) {
                                        bfs.push({i, j, 0});
                                        visited[i][j][k] = true;
                                }
                                else if (box[i][j][k] == -1)
                                        visited[i][j][k] = true;
                        }
                }   
        }
                
        if (bfs.empty()) {
                cout << "-1\n";
                return 0;
        }

        while (!bfs.empty()) {
                auto a = bfs.front();
                bfs.pop();
                cnt = max(cnt, a.cnt);

                for (int i = 0; i < 6; i++) {
                        int nx = a.x + moveX[i];
                        int ny = a.y + moveY[i];
                        int nz = a.z + moveZ[i];

                        if (nx >= 0 && ny >=0 && nz>=0 && nx < N && ny < M && nz < Z && !visited[nx][ny][nz] && box[nx][ny][nz] != -1) {
                                bfs.push({nx, ny, nz, a.cnt + 1});
                                visited[nx][ny][nz] = true;
                        }
                }
        }

        for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                        for(int k=0; k<Z; k++) {
                                if (!visited[i][j][k]) {
                                        cout << "-1\n";
                                        return 0;
                                }
                        }
                        
                }
        }
                      
        cout << cnt << "\n";
        return 0;
}