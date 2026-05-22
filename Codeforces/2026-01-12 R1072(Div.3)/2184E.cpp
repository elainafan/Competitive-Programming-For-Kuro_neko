#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i <= n - 1; i++) cin >> a[i];
    vector<int> res(n - 1);
    vector<int> diff(n - 1);
    for (int i = 0; i < n - 1; i++) diff[i] = abs(a[i + 1] - a[i]);
    vector<int> r(n - 1, n - 1);
    vector<int> l(n - 1, -1);
    stack<int> s;
    vector<vector<int>> ma(n);
    for (int i = 0; i < n - 1; i++) ma[diff[i]].push_back(i);
    for (int i = n - 2; i >= 0; i--) {
        while (!s.empty() && diff[s.top()] >= diff[i]) s.pop();
        if (!s.empty()) r[i] = s.top();
        s.push(i);
    }
    while (!s.empty()) s.pop();
    for (int i = 0; i <= n - 2; i++) {
        while (!s.empty() && diff[s.top()] > diff[i]) s.pop();
        if (!s.empty()) l[i] = s.top();
        s.push(i);
    }
    vector<ll> ans(n);
    ll cnt = 0;
    for (int i = n - 1; i >= 1; i--) {
        for (int p : ma[i]) {
            cnt += 1LL * (r[p] - p) * (p - l[p]);
        }
        ans[i] = cnt;
    }
    for (int i = 1; i <= n - 1; i++) cout << ans[i] << ' ';
    cout << endl;
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