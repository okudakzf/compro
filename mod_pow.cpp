#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod_pow(int n, int p, int mod){
    // return (n^p) % mod
    if(p==0) return 1;
    ll res = mod_pow(n*n%mod, p/2, mod);
    if(p%2==1) res = res * n % mod;
    return res;
}
