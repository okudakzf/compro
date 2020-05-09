#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

vector<pair<int, int>> primeFactorization(ll n) {
    vector<pair<int, int>> result;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            result.push_back({i, 0});
            while (n % i == 0) {
                result.back().second++;
                n /= i;
            }
        }
    }
    if (n > 1) {
        result.push_back({n, 1});
    }
    return result;
}
