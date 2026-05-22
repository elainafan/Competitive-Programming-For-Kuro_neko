#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
using namespace std;
void solve() {
    int n, h, l;
    cin >> n >> h >> l;
    vector<int> a(n);
    for (int i = 0; i <= n - 1; i++) cin >> a[i];
    ranges::sort(a);
    int ans = 0;
    int t = max(h, l), m = min(h, l);
    auto x = ranges::upper_bound(a, t);
    auto y = ranges::upper_bound(a, m);
    int tem = x - a.begin(), tem2 = y - a.begin();
    int res = tem - tem2;
    int res2 = tem2;
    if (res > res2)
        cout << res2 << endl;
    else
        cout << res + (res2 - res) / 2 << endl;
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