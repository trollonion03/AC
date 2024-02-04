/**************************************************************
* Time-saving Solution (C&C++)
* CURRENT	: 	4485
* RETRY     :   0
***************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <cstdio> // 시간초과 이슈로 printf(), scanf() 사용

using namespace std;
constexpr int INF = 0x3f3f3f3f;
typedef long long ll;
typedef unsigned long long ull;

#define MAXN 126

int n;
int a[MAXN][MAXN];
int d[MAXN][MAXN];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void init() {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            d[i][j] = INF;
        }
    }
}

void dijkstra() {
    init();
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({-a[1][1], {1, 1}});
    d[1][1] = a[1][1];
    
    while(!pq.empty()) {
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        int dist = -pq.top().first;
        pq.pop();
        
        if(d[x][y] < dist) {
            continue;
        }

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int ndist = dist + a[nx][ny];
            
            if(nx>0 && ny>0 && nx<=n && ny<=n) {
                if(ndist < d[nx][ny]) {
                    d[nx][ny] = ndist;
                    pq.push({-ndist, {nx, ny}});
                }
            }
        }
    }
}

int main() {
    int cnt = 1;
    while(true) {
        scanf("%d", &n);
        if(n == 0) break;
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                scanf("%d", &a[i][j]);
            }
        }
        dijkstra();
        printf("Problem %d: %d\n", cnt++, d[n][n]);
    }

    return 0;
}