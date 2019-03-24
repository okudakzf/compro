#include <bits/stdc++.h>
using namespace std;

struct union_find{
    union_find(int n){
        par = vector<int>(n+1, -1);
    }
    int find(int x){
        if(par[x] < 0) return x;
        else return par[x] = find(par[x]);
    }
    bool same(int x, int y){
        return find(x) == find(y);
    }
    void unite(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return;
        if(par[x] < par[y]) swap(x,y);
        par[x] += par[y];
        par[y] = x;
    }
    int getSize(int x){
        return -par[x];
    }

    private:
        vector<int> par;
};
