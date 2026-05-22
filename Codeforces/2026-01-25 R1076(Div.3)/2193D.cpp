#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i <= n - 1; i++) cin >> a[i];
    for (int i = 0; i <= n - 1; i++) cin >> b[i];
    sort(a.rbegin(), a.rend());
    vector<ll> pre(n, 0);
    pre[0] = b[0];
    for (int i = 1; i <= n - 1; i++) pre[i] = pre[i - 1] + 1LL * b[i];
    ll ans = 0;
    map<int, int> ma;
    for (int p : a) ma[p]++;
    int cnt = 0;
    for (auto it = (--ma.end());; it--) {
        int tem = it->first;
        cnt += it->second;
        auto x = ranges::upper_bound(pre, cnt);
        if (x == pre.begin()) continue;
        int tem2 = x - pre.begin();
        ans = max(ans, 1LL * tem * tem2);
        if (it == ma.begin()) break;
    }
    cout << ans << endl;
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