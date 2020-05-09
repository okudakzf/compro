#include <bits/stdc++.h>
#define ll long long
#define inf 1e15
using namespace std;

struct edge {
    int to;
    ll cost;
};

vector<ll> dijkstra(vector<vector<edge>>& graph, int start) {
    int N = graph.size();
    vector<ll> dist(N, 1e18);
    dist[start] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> que;
    que.push({0, start});
    while (!que.empty()) {
        auto p = que.top();
        ll d = p.first;
        int u = p.second;
        que.pop();
        if (dist[u] < d) {
            continue;
        }

        for (auto e : graph[u]) {
            int v = e.to;
            int c = e.cost;
            if (dist[v] > dist[u] + c) {
                dist[v] = dist[u] + c;
                que.push({dist[v], v});
            }
        }
    }

    return dist;
}
