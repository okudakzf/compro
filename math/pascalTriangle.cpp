#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct pascal_triangle {
    pascal_triangle(ll Nmax, ll mod) {
        (this->MOD) = mod;
        (this->Nmax) = Nmax;
        value.resize(Nmax, vector<ll>(Nmax, -1));
    }

    ll calc(ll n, ll r) {
        if (value[n][r] != -1)
            return value[n][r];
        if (n == r || r == 0) {
            value[n][r] = 1;
        } else {
            value[n][r] = (calc(n - 1, r - 1) + calc(n - 1, r)) % MOD;
        }
        return value[n][r];
    }

private:
    ll MOD, Nmax;
    vector<vector<ll>> value;
};
