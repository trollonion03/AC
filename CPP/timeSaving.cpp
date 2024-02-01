/**************************************************************
* Time-saving Solution (C&C++)
* CURRENT	: 	18223
* RETRY     :   1
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

#define MAXN 5001

int v, e, p;
vector<pair<int, int>> a[MAXN];
int d[MAXN];
int ans[MAXN];
int res = -1;

void init() {
    for(int i=1; i<=v; i++) {
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
    scanf("%d %d %d", &v, &e, &p);

    for(int i=0; i<e; i++) {
        int aa, b, c;
        scanf("%d %d %d", &aa, &b, &c);
        a[aa].push_back({b, c});
        a[b].push_back({aa, c});
    }

    init();
    dijkstra(1);
    
    int t1 = d[p];
    int t2 = d[v];

    dijkstra(p);
    t1 += d[v];

    if(t1 == t2) {
        printf("SAVE HIM\n");
    }
    else {
        printf("GOOD BYE\n");
    }

    return 0;
}