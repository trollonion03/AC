/**************************************************************
* Time-saving Solution (C&C++)
* CURRENT	: 	14938
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

#define MAXN 101

int n, m, r;
vector<pair<int, int>> a[MAXN];
int d[MAXN];
int item[MAXN];
int sc, ans = -1;

void init() {
    sc = 0;
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
    scanf("%d %d %d", &n, &m, &r);

    for(int i=1; i<=n; i++) {
        scanf("%d", &item[i]);
    }

    for(int i=0; i<r; i++) {
        int aa, b, c;
        scanf("%d %d %d", &aa, &b, &c);
        a[aa].push_back({b, c});
        a[b].push_back({aa, c});
    }

    for(int i=1; i<=n; i++) {
        init();
        dijkstra(i);
        for(int j=1; j<=n; j++) {
            if(d[j] <= m) {
                sc += item[j];
            }
        }
        ans = max(ans, sc);
    }
    
    printf("%d\n", ans);

    return 0;
}