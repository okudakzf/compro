#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll ceil(ll a, ll b) {
    if (b < 0) {
        a *= -1;
        b *= -1;
    }
    if (a >= 0) {
        return (a + b - 1) / b;
    } else {
        return a / b;
    }
}

ll floor(ll a, ll b) {
    if (b < 0) {
        a *= -1;
        b *= -1;
    }
    if (a < 0) {
        return (a - b + 1) / b;
    } else {
        return a / b;
    }
}
