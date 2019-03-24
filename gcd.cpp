#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(a<b) swap(a,b);
    if(a%b==0) return b;
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
