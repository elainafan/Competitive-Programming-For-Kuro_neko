#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
using namespace std;
void solve() {
    int n, s, x;
    cin >> n >> s >> x;
    ll ans = 0;
    vector<int> a(n);
    for (int i = 0; i <= n - 1; i++) {
        cin >> a[i];
        ans += 1LL * a[i];
    }
    if (s < ans || (s - ans) % x != 0)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
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