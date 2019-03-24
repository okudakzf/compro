#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<ll>> c;

ll comb(ll n, ll m){
    if(c[n][m] != -1) return c[n][m];
    if(n==m || m==0){
        c[n][m] = 1;
    }else{
        c[n][m] = comb(n-1,m-1) + comb(n-1,m);
    }
    return c[n][m];
}
