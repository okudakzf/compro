#include <bits/stdc++.h>
#define ll long long
using namespace std;

// 1が立っているビットの数を数える。
int cntbit(int A) { return (A < 2) ? 1 : 1 + cntbit(A / 2); }

// Aの下からKbit目(0-indexed)を返す
int kthbit(int A, int K) { return (A >> K) & 1; }

// Aの下からKbitを取り出す
int mask(int A, int K) { return A & ((1 << K) - 1); }

// wbit整数Aをkbitだけ左に回す
// kが負なら右に回す
int slide(int A, int w, int k) {
    if (k >= 0) {
        return (mask(A, w - k) << k) + (A >> (w - k));
    } else {
        return (A >> (-k)) + (mask(A, -k) << (w - (-k)));
    }
}
