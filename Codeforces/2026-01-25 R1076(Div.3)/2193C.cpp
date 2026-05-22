#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
using namespace std;
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i <= n - 1; i++) cin >> a[i];
    for (int i = 0; i <= n - 1; i++) cin >> b[i];
    int l, r;
    vector<int> suf(n, INT_MIN);
    suf[n - 1] = max(a[n - 1], b[n - 1]);
    for (int i = n - 2; i >= 0; i--) suf[i] = max(suf[i + 1], max(a[i], b[i]));
    vector<ll> suf2(n + 2, 0);
    for (int i = n; i >= 1; i--) suf2[i] = suf2[i + 1] + 1LL * suf[i - 1];
    for (int i = 0; i <= q - 1; i++) {
        cin >> l >> r;
        cout << suf2[l] - suf2[r + 1] << ' ';
    }
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