#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

map<int, int> compress(vector<int> v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    map<int, int> mp;
    for (int i = 0; i < v.size(); i++) {
        mp[v[i]] = i;
    }
    return mp;
}
