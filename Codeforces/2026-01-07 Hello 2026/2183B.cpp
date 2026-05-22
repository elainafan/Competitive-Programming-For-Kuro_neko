#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
using namespace std;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i <= n - 1; i++) cin >> a[i];
    map<int, int> ma;
    for (int p : a) ma[p]++;
    int cnt = 0;
    if (!ma.count(0)) {
        cout << 0 << endl;
        return;
    }
    for (auto [x, y] : ma) {
        if (x == cnt)
            cnt++;
        else
            break;
        if (cnt == k - 1) break;
    }
    cout << cnt << endl;
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