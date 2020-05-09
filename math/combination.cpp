#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll mod_pow(ll n, ll p, ll mod) {
    n %= mod;
    if (p == 0)
        return 1;
    ll res = mod_pow(n * n % mod, p / 2, mod);
    if (p % 2 == 1)
        res = res * n % mod;
    return res;
}

struct combination {
    combination(ll Nmax, ll mod) {
        (this->MOD) = mod;
        (this->Nmax) = Nmax;
        factorial.resize(Nmax + 1, 1);
        inverse_factorial.resize(Nmax + 1, 1);
        init_factorial();
    }

    ll calc(ll n, ll r) {
        if (r < 0 || r > n)
            return 0;
        ll ret = (factorial[n] * inverse_factorial[r]) % MOD;
        ret = (ret * inverse_factorial[n - r]) % MOD;
        return ret;
    }

    vector<ll> factorial;
    vector<ll> inverse_factorial;

private:
    ll MOD, Nmax;

    void init_factorial() {
        for (ll i = 1; i <= Nmax; i++) {
            factorial[i] = (factorial[i - 1] * i) % MOD;
        }
        inverse_factorial[Nmax] = mod_pow(factorial[Nmax], MOD - 2, MOD);
        for (ll i = Nmax - 1; i >= 1; i--) {
            inverse_factorial[i] = (inverse_factorial[i + 1] * (i + 1)) % MOD;
        }
    }
};
