#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
using namespace std;
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int las = -1, tem = 1;
    int ans = INT_MAX;
    vector<int> res;
    for (int i = 1; i <= n - 1; i++) {
        if (s[i] == s[i - 1])
            tem++;
        else {
            res.push_back(tem);
            tem = 1;
        }
    }
    res.push_back(tem);
    int m = res.size();
    vector<int> maxx(m, 0);
    maxx[m - 2] = res[m - 2];
    for (int i = m - 4; i >= 0; i -= 2) {
        maxx[i] = maxx[i + 2] + res[i];
    }
    if (m > 2 && maxx[2] > 1)
        cout << n - 2 << endl;
    else
        cout << -1 << endl;
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}