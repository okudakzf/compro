#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
    SegmentTree(vector<int> v, int ini) {
        int sz = v.size();
        n = 1;
        while (n < sz) n *= 2;
        node.resize(2 * n - 1, ini);

        for (int i = 0; i < sz; i++) {
            node[i + n - 1] = v[i];
        }
        for (int i = n - 2; i >= 0; i--) {
            node[i] = min(node[2 * i + 1], node[2 * i + 2]);
        }
    }

    void update(int k, int val) {
        k += n - 1;
        node[k] = val;
        while (k > 0) {
            k = (k - 1) / 2;
            node[k] = min(node[2 * k + 1], node[2 * k + 2]);
        }
    }

    int query(int a, int b, int k = 0, int l = 0, int r = -1) {
        if (r < 0) r = n;

        if (r <= a || b <= l) return INT_MAX;
        if (a <= l && r <= b) return node[k];

        int vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
        int vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
        return min(vl, vr);
    }

   private:
    int n;
    vector<int> node;
};
