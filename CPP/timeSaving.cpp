/**************************************************************
* Time-saving Solution (C&C++)
* CURRENT	: 	23793
* RETRY     :   2
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

#define MAXN 100001

int n, m, x, y, z;
vector<pair<int, int>> a[MAXN];
int d[MAXN];
int res1, res2;

void init() {
    for(int i=1; i<=n; i++) {
        d[i] = INF;
    }
}

void dijkstra(int s, int av) {
    init();
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
            
            if(ndist < d[next] && next != av) {
                d[next] = ndist;
                pq.push({-ndist, next});
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);

    for(int i=0; i<m; i++) {
        int aa, b, c;
        scanf("%d %d %d", &aa, &b, &c);
        a[aa].push_back({b, c});
    }

    scanf("%d %d %d", &x, &y, &z);

    
    dijkstra(x, -1);
    int t1 = d[y];
    dijkstra(y, -1);
    int t2 = d[z];
    dijkstra(x, y);
    int t3 = d[z];


    if(t1 == INF || t2 == INF) {
        res1 = -1;
    }
    else {
        res1 = t1+t2;
    }
    if(t3 == INF) {
        res2 = -1;
    }
    else {
        res2 = t3;
    }

    printf("%d %d\n", res1, res2);

    return 0;
}