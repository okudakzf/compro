#include <bits/stdc++.h>
#define ll long long
#define P pair<ll, int> // <Minimum distance, Vertex number>
#define inf 1e15
using namespace std;

struct edge {
    int to;
    ll cost;
};

vector<ll> dijkstra(vector<vector<edge>> E, int N) {
    vector<ll> dist(N + 1, inf);
    priority_queue<P, vector<P>, greater<P>> que;
    dist[1] = 0;
    que.push(P(0, 1));
    while (!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;
        if (dist[v] < p.first)
            continue;

        for (int i = 0; i < E[v].size(); i++) {
            edge e = E[v][i];
            if (dist[e.to] > dist[v] + e.cost) {
                dist[e.to] = dist[v] + e.cost;
                que.push(P(dist[e.to], e.to));
            }
        }
    }

    return dist;
}
