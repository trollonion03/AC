/**************************************************************
* Time-saving Solution (C&C++)
* CURRENT	: 	1916
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

int n, m, v1, v2;
vector<pair<int, int>> a[8001];
int d[8001];

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

    for(int i=1; i<=n; i++) {
        d[i] = INF;
    }
    dijkstra(v1);
    cout << d[v2] << "\n";

    return 0;
}