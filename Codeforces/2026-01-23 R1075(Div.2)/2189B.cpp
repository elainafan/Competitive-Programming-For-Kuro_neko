#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
using namespace std;
void solve() {
    int n;
    ll x;
    cin >> n >> x;
    vector<tuple<ll, ll, ll, ll>> ma(n);
    ll a, b, c;
    bool flag = false;
    ll ans = 0;
    for (int i = 0; i <= n - 1; i++) {
        cin >> a >> b >> c;
        ma[i] = make_tuple(1LL * a * b - 1LL * c, 1LL * a * (b - 1), a, c);
        if (1LL * c < 1LL * b * a) flag = true;
        ans += 1LL * a * (b - 1);
    }
    if (!flag && x > ans) {
        cout << -1 << endl;
        return;
    }
    if (x <= ans) {
        cout << 0 << endl;
        return;
    }
    sort(ma.rbegin(), ma.rend());
    ll tem = get<0>(ma[0]);
    if ((x - ans) % tem == 0)
        cout << (x - ans) / tem << endl;
    else
        cout << (x - ans) / tem + 1 << endl;
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