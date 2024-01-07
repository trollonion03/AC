// RETRY: 6
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>

using namespace std;
constexpr int INF = 987654321;

int v, e, k;
vector<pair<int, int>> a[20001];
int d[20001];

void dijkstra() {
    priority_queue<pair<int, int>> pq;
    pq.push({0, k});
    d[k] = 0;

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

    for(int i=1; i<=v; i++) {
        if(d[i] == INF)
            printf("%s\n", "INF");
        else
            printf("%d\n", d[i]);
    }
}

int main() {
    scanf("%d %d", &v, &e);
    scanf(" %d", &k);

    for(int i=0; i<e; i++) {
        int aa, b, c;
        scanf("%d %d %d", &aa, &b, &c);
        a[aa].push_back({b, c});
    }

    for(int i=1; i<=v; i++) {
        d[i] = INF;
    }

    dijkstra();
    return 0;
}