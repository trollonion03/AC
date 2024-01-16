/**************************************************************
* Time-saving Solution (C&C++)
* CURRENT	: 	1238
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

#define MAXN 1010

int n, m, v;
vector<pair<int, int>> a[MAXN];
int d[MAXN];
int ans[MAXN];
int res = -1;

void init() {
    for(int i=1; i<=n; i++) {
        d[i] = INF;
    }
}

void dijkstra(int s) {
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
}

int main() {
    scanf("%d %d %d", &n, &m, &v);

    for(int i=0; i<m; i++) {
        int aa, b, c;
        scanf("%d %d %d", &aa, &b, &c);
        a[aa].push_back({b, c});
    }

    for(int i=1; i<=n; i++) {
        init();
        dijkstra(i);
        ans[i] = d[v];
    }
    init();
    dijkstra(v);
    for(int i=0; i<=n; i++) {
        ans[i] += d[i];
        res = max(res, ans[i]);
    }
    printf("%d\n", res);

    return 0;
}