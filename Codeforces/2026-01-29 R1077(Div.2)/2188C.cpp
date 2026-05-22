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
    auto b = a;
    ranges::sort(b);
    bool flag = true;
    map<int, set<int>> ma;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] <= a[i + 1]) continue;
        flag = false;
        break;
    }
    if (flag) {
        cout << -1 << endl;
        return;
    }
    int maxx = *max_element(a.begin(), a.end());
    int mixx = *min_element(a.begin(), a.end());
    int ans = INT_MAX;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] != b[i]) {
            int tem2 = max(maxx - a[i], a[i] - mixx);
            ans = min(ans, tem2);
        }
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
