#include <bits/stdc++.h>
using namespace std;

string addString(string s, string t) {
    string ans = "";
    if (s.size() > t.size()) {
        swap(s, t);
    }
    while (t.size() > s.size()) {
        s = '0' + s;
    }
    int dig = 0;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        int ret = dig + (s[n - i - 1] - '0') + (t[n - i - 1] - '0');
        dig = ret / 10;
        ret %= 10;
        ans = (char)(ret + '0') + ans;
    }
    if (dig)
        ans = '1' + ans;
    return ans;
}
