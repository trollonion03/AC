/**************************************************************
* Time-saving Solution (C&C++)
* CURRENT	: 	1504
* RETRY     :   0
***************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <cstdio> // 시간초과 이슈로 printf(), scanf() 사용

using namespace std;
constexpr int INF = 987654321;
typedef long long ll;
typedef unsigned long long ull;

int v, e, k, v1, v2;
vector<pair<int, int>> a[8001];
int d[8001];

void dijkstra(int s) {
    priority_queue<pair<int, int>> pq;
    pq.push({0, s});
    d[s] = 0;

    while(!pq.empty()) {
        int dist = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(d[cur] < dist)
            continue;

        for(int i=0; i<a[cur].size(); i++) {
            int next = a[cur][i].first;
            int ndist = dist + a[cur][i].second;

            if(ndist < d[next]) {
                d[next] = ndist;
                pq.push({-ndist, next});
            }
        }
    }
}

int main() {
    scanf("%d %d", &v, &e);

    for(int i=0; i<e; i++) {
        int aa, b, c;
        scanf("%d %d %d", &aa, &b, &c);
        a[aa].push_back({b, c});
        a[b].push_back({aa, c});
    }
    scanf("%d %d", &v1, &v2);

    for(int i=1; i<=v; i++) {
        d[i] = INF;
    }
    dijkstra(v1);
    ll distV1_1 = d[1];
    ll distV1_V2 = d[v2];
    ll distV1_E = d[v];
    for(int i=1; i<=v; i++) {
        d[i] = INF;
    }
    dijkstra(v2);
    ll distV2_1 = d[1];
    ll distV2_E = d[v];

    ll tmp1 = distV1_1 + distV1_V2 + distV2_E;
    ll tmp2 = distV2_1 + distV1_V2 + distV1_E;

    ll ans = min(tmp1, tmp2);
    if(ans >= INF) {
        printf("%d\n", -1);
    }
    else {
        printf("%lld", ans);
    }

    return 0;
}