/**************************************************************
* Time-saving Solution (C&C++)
* CURRENT	: 	10282
* RETRY     :   0
***************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cstdio> // 시간초과 이슈로 printf(), scanf() 사용

using namespace std;
constexpr int INF = 987654321;
typedef long long ll;
typedef unsigned long long ull;

#define MAXN 50001

int t, n, m, r;

void dijkstra(int s, vector<pair<int, int>> *a) {
    int sec = 0, cnt = 0;
    int d[MAXN];
    for(int i=1; i<=n; i++) {
        d[i] = INF;
    }
    priority_queue<pair<int, int>> pq;
    pq.push({0, s});
    d[s] = 0;

    while(!pq.empty()) {
        int cur = pq.top().second;
        int dist = -pq.top().first;
        pq.pop();

        if(d[cur] < dist) {
            continue;
        }

        for(int i=0; i<a[cur].size(); i++) {
            int next = a[cur][i].first;
            int ndist = dist + a[cur][i].second;

            if(ndist < d[next]) {
                d[next] = ndist;
                pq.push({-ndist, next});
            }
        }
    }

    for(int i=1; i<=n; i++) {
        if(d[i] != INF) {
            cnt++;
            sec = max(d[i], sec);
        }
    }
    printf("%d %d\n", cnt, sec);
}

int main() {
    scanf("%d", &t);
    for(int i=0; i<t; i++) {
        vector<pair<int, int>> a[MAXN];
        scanf("%d %d %d", &n, &m, &r);
        for(int j=0; j<m; j++) {
            int aa, b, c;
            scanf("%d %d %d", &aa, &b, &c);
            a[b].push_back({aa, c});
        }
        dijkstra(r, a);
    }

    return 0;
}