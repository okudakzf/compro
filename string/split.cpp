#include <bits/stdc++.h>
using namespace std;

vector<string> split(string s, char delimiter) {
    int start = 0;
    int n = s.length();
    vector<string> result;
    for (int i = 0; i < n; i++) {
        if (s[i] == delimiter) {
            result.push_back(s.substr(start, i - start));
            start = i + 1;
            if (i == n - 1) {
                result.push_back("");
            }
        } else if (i == n - 1) {
            result.push_back(s.substr(start));
        }
    }
    return result;
}
