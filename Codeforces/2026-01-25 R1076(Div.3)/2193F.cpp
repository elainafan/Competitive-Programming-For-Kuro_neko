#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
using namespace std;
void solve() {
    int n, ax, ay, bx, by;
    cin >> n >> ax >> ay >> bx >> by;
    vector<pair<int, int>> ma(n);
    for (int i = 0; i <= n - 1; i++) cin >> ma[i].first;
    for (int i = 0; i <= n - 1; i++) cin >> ma[i].second;
    ranges::sort(ma);
    map<int, vector<int>> s;
    map<int, vector<ll>> s2;
    s[ax].push_back(ay);
    s2[ax].push_back(0);
    s[bx].push_back(by);
    s2[bx].push_back(LLONG_MAX);
    for (auto& [x, y] : ma) {
        s[x].push_back(y);
        s2[x].push_back(LLONG_MAX);
    }
    for (auto it = s.begin(); it != s.end(); it++) {
        auto itt = it;
        itt++;
        if (itt == s.end()) break;
        int tem = it->second.size();
        int tem2 = itt->second.size();
        int x = it->first;
        int x2 = itt->first;
        ll d = x2 - x;
        ll d2 = 1LL * abs(itt->second[tem2 - 1] - itt->second[0]);
        s2[x2][0] = min(s2[x2][0], s2[x][0] + d + 1LL * abs(it->second[0] - itt->second[tem2 - 1]) + d2);
        s2[x2][0] = min(s2[x2][0], s2[x][tem - 1] + d + 1LL * abs(it->second[tem - 1] - itt->second[tem2 - 1]) + d2);
        s2[x2][tem2 - 1] = min(s2[x2][tem2 - 1], s2[x][0] + d + 1LL * abs(it->second[0] - itt->second[0]) + d2);
        s2[x2][tem2 - 1] = min(s2[x2][tem2 - 1], s2[x][tem - 1] + d + 1LL * abs(it->second[tem - 1] - itt->second[0]) + d2);
    }
    cout << s2[bx][0] << endl;
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