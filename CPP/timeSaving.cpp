/**************************************************************
* Time-saving Solution (C&C++)
* CURRENT	: 	20007
* RETRY     :   3
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

#define MAXN 1001

int n, m, x, y;
int sum = 0, day = 1;
vector<pair<int, int>> a[MAXN];
int d[MAXN];
int ans[MAXN];

void init() {
    for(int i=0; i<n; i++) {
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
                d[next] = ndist;
                pq.push({-ndist, next});
            }
        }
    }
}

int main() {
    scanf("%d %d %d %d", &n, &m, &x, &y);
    for(int i=0; i<m; i++) {
        int aa, b, c;
        scanf("%d %d %d", &aa, &b, &c);
        a[aa].push_back({b, c});
        a[b].push_back({aa, c});
    }
    dijkstra(y);
    for(int i=0; i<n; i++) {
        if(d[i]*2 > x) {
            printf("-1\n");
            return 0;
        }
    }
    sort(d, d+n);
    for(int i=0; i<n; i++) {
        if(sum + d[i] * 2 <= x) {
            sum += d[i]*2;
        }
        else {
            day++;
            sum = 2*d[i];
        }
    }
    printf("%d\n", day);
    return 0;
}