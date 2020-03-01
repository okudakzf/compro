#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll modPow(ll n, ll p, ll mod) {
    n %= mod;
    // return (n^p) % mod
    if (p == 0)
        return 1;
    ll res = modPow(n * n % mod, p / 2, mod);
    if (p % 2 == 1)
        res = res * n % mod;
    return res;
}
