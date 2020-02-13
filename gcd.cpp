#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
    if(b==0) return a;
    else return gcd(b, a%b);
}

int extGCD(int a, int b, int &x, int &y){
    // ax + by = gcd(a,b)
    // d = gcd(a,b)
    // x, y には解が格納される。
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int d = extGCD(b, a%b, y, x);
    y -= a/b * x;
    return d;
}
