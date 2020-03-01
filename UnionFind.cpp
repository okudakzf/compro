#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    UnionFind(int n) {
        parent = vector<int>(n, -1);
        weight = vector<int>(n, 0);
    }
    int find(int x) {
        if (parent[x] < 0)
            return x;
        else
            return parent[x] = find(parent[x]);
    }
    bool isSame(int x, int y) { return find(x) == find(y); }
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            weight[x]++;
            return;
        }
        if (parent[x] < parent[y])
            swap(x, y);
        parent[x] += parent[y];
        parent[y] = x;
        weight[x] += weight[y] + 1;
    }
    int getSize(int x) { return -parent[find(x)]; }
    int getWeight(int x) { return weight[find(x)]; }

private:
    vector<int> parent;
    vector<int> weight;
};
