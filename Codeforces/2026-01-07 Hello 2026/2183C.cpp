#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
using namespace std;
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int l = k - 1, r = n - k;
    if (l > r) swap(l, r);
    if (max(2 * r - 1 + l, l + 2 * r - 1) <= m) {
        cout << n << endl;
        return;
    }
    int tem = 0;
    int tem2 = 0;
    int t = min(l, (m + 1) / 3);
    tem = t + 1 + min(r, (m + 1 - t) / 2);
    cout << tem << endl;
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