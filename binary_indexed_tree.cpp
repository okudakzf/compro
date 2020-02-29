#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct BinaryIndexedTree {
    BinaryIndexedTree(int N) { bit.resize(N + 1, 0); }

    T sum(int i) {
        if (i == 0) return 0;
        return bit[i] + sum(i & (i - 1));
    }

    void add(int i, T val) {
        if (i >= bit.size()) return;
        bit[i] += val;
        add(i + (i & -i), val);
    }

   private:
    vector<T> bit;
};
