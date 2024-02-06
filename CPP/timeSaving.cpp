/**************************************************************
* Time-saving Solution (C&C++)
* CURRENT	: 	13424
* RETRY     :   4
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

#define MAXN 101

int t, n, m, k;
int d[MAXN];
int ans[MAXN];

void init() {
    for(int i=1; i<=n; i++) {
        d[i] = INF;
    }
}

void dijkstra(int x, vector<pair<int,int>> *a) {
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
    scanf("%d", &t);
    while(t--) {
        vector<pair<int, int>> a[MAXN];
        vector<int> r;
        scanf("%d %d", &n, &m);
        for(int i=0; i<m; i++) {
            int aa, b, c;
            scanf("%d %d %d", &aa, &b, &c);
            a[aa].push_back({b, c});
            a[b].push_back({aa, c});
        }
        scanf("%d", &k);
        for(int i=0; i<k; i++) {
            int tmp;
            scanf("%d", &tmp);
            r.push_back(tmp);
        }
        for(int i=0; i<k; i++) {
            dijkstra(r[i], a);
            for(int j=1; j<=n; j++) {
                ans[j] += d[j];
            }
        }
        int val = INF;
        int num = 0;
        for(int i=1; i<=n; i++) {
            if(ans[i] < val) {
                num = i;
                val = ans[i];
            }
        }
        printf("%d\n", num);

        memset(ans, 0, sizeof(ans));
    }
    return 0;
}