/**************************************************************
* Time-saving Solution (C&C++)
* CURRENT	: 	9505
* RETRY     :   8
***************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;
constexpr int INF = 0x3f3f3f3f;
typedef long long ll;
typedef unsigned long long ull;

#define MAXN 1001

int t, k, w, h;
int a[MAXN][MAXN];
int d[MAXN][MAXN];
int def[27];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int sx, sy;

void init() {
    for(int i=1; i<=h; i++) {
        for(int j=1; j<=w; j++) {
            d[i][j] = INF;
        }
    }
}

void dijkstra() {
    init();
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({-a[sx][sy], {sx, sy}});
    d[sx][sy] = a[sx][sy];
    
    while(!pq.empty()) {
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        int dist = -pq.top().first;
        pq.pop();
        
        if(d[x][y] < dist) {
            continue;
        }

        if(x == h || x == 1 || y == w || y == 1) {
            printf("%d\n", dist);
            return;
        }

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int ndist = dist + a[nx][ny];
            
            if(nx>0 && ny>0 && nx<=h && ny<=w) {
                if(ndist < d[nx][ny]) {
                    d[nx][ny] = ndist;
                    pq.push({-ndist, {nx, ny}});
                }
            }
        }
    }
}

int main() {
    scanf("%d", &t);
    for(int m=0; m<t; m++) {
        scanf("%d %d %d", &k, &w, &h);
        for(int i=0; i<k; i++) {
            char ch; int bb;
            scanf(" %c %d", &ch, &bb);
            def[ch-'A'] = bb;
        }
        for(int i=1; i<=h; i++) {
            for(int j=1; j<=w; j++) {
                char ch;
                scanf(" %c", &ch);
                a[i][j] = def[ch-'A'];
                if(ch == 'E') {
                    sx = i;
                    sy = j;
                }
            }
        }
        dijkstra();
    }

    return 0;
}