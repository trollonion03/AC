/**************************************************************
* Time-saving Solution (C&C++)
* CURRENT	: 	11779
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

#define MAXN 1010

int n, m, v1, v2;
vector<pair<int, int>> a[MAXN];
stack<int> ans;
int d[MAXN];
int l[MAXN];

void init() {
    for(int i=1; i<=n; i++) {
        d[i] = INF;
    }
}

void dijkstra(int s) {
    priority_queue<pair<int, int>> pq;
    pq.push({0, s});
    
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
                l[next] = cur;
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    scanf("%d", &m);

    for(int i=0; i<m; i++) {
        int aa, b, c;
        scanf("%d %d %d", &aa, &b, &c);
        a[aa].push_back({b, c});
    }
    scanf("%d %d", &v1, &v2);

    init();
    dijkstra(v1);
    printf("%d\n", d[v2]);
    while(true) {
        ans.push(v2);
        if(v2 == v1) {
            break;
        }
        v2 = l[v2];
    }
    printf("%d\n", ans.size());
    while(!ans.empty()) {
        printf("%d ", ans.top());
        ans.pop();
    }
    printf("\n");

    return 0;
}