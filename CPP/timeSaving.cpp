/**************************************************************
* Time-saving Solution (C&C++)
* CURRENT	: 	1719
* RETRY     :   0
***************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
constexpr int INF = 0x3f3f3f3f;
typedef long long ll;
typedef unsigned long long ull;

#define MAXN 201

int n, m;
vector<pair<int, int>> a[MAXN];
int d[MAXN];
int ans[MAXN];
int log[MAXN];

void init() {
    for(int i=1; i<=n; i++) {
        d[i] = INF;
    }
}

void dijkstra(int x) {
    init();
    priority_queue<pair<int, int>> pq;
    pq.push({0, x});
    d[x] = 0;
    
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
                // log[next] = cur;
                if(cur == x) {
                    log[next] = next;
                }
                else {
                    log[next] = log[cur];
                }
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
        a[b].push_back({aa, c});
    }
    for(int i=1; i<=n; i++) {
        dijkstra(i);
        for(int j=1; j<=n; j++) {
            if(j != i) {
                printf("%d ", log[j]);
            }
            else {
                printf("- ");
            }
        }
        printf("\n");
    }
    
    return 0;
}