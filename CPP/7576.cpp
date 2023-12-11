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
#define MAXN 1001

typedef struct types {
        int x;
        int y;
        int cnt;
}types;

bool visited[1001][1001];
int box[1001][1001];
int moveX[4] = {1, 0, -1, 0};
int moveY[4] = {0, 1, 0, -1};
int M, N;       //가로, 세로

queue<types> bfs;

int main(void) 
{
        ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

        int cnt = 0;
        scanf("%d %d", &M, &N);
        for (int i = 0; i < N; i++)
                for (int j = 0; j < M; j++) {
                        scanf("%d", &box[i][j]);
                        if (box[i][j] == 1) {
                                bfs.push({i, j, 0});
                                visited[i][j] = true;
                        }
                        else if (box[i][j] == -1)
                                visited[i][j] = true;
                }
        if (bfs.empty()) {
                printf("-1");
                return 0;
        }

        while (!bfs.empty()) {
                auto a = bfs.front();
                bfs.pop();
                cnt = max(cnt, a.cnt);

                for (int i = 0; i < 4; i++) {
                        int nx = a.x + moveX[i];
                        int ny = a.y + moveY[i];

                        if (nx >= 0 && ny >=0 && nx < N && ny < M && !visited[nx][ny] && box[nx][ny] != -1) {
                                bfs.push({nx, ny, a.cnt + 1});
                                visited[nx][ny] = true;
                        }
                }
        }

        for (int i = 0; i < N; i++)
                for (int j = 0; j < M; j++)
                        if (!visited[i][j]) {
                                printf("-1");
                                return 0;
                        }

        printf("%d", cnt);
        return 0;
}