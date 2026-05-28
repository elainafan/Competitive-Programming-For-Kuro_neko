#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
#define rep(i, x, y) for (int i = x; i <= y; i++)
#define frep(i, x, y) for (int i = x; i >= y; i--)
#define all(x) (x).begin(), (x).end()
#define all2(x) (x).rbegin(), (x).rend()
#define sz(a) (int)a.size()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define tri tuple<int, int, int>
#define trl tuple<ll, ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define pq priority_queue
#define umap unordered_map
#define mset multiset
using namespace std;
void solve() {
    ll n, l, r;
    cin >> n >> l >> r;
    vl a(n + 2);
    rep(i, 1, n) cin >> a[i];
    vl pre(n + 2);
    vl pre2(n + 2);
    vl pre3(n + 2);
    rep(i, 1, n) {
        pre[i] = pre[i - 1] ^ a[i];
        pre2[i] = pre2[i - 1] + a[i];
        pre3[i] = pre3[i - 1] + pre[i];
    }
    if (n % 2 == 0) {
        a[n + 1] = pre[n / 2];
        pre[n + 1] = pre[n] ^ a[n + 1];
        pre2[n + 1] = pre2[n] + a[n + 1];
        pre3[n + 1] = pre3[n] + pre[n + 1];
        n++;
    }
    auto calc3 = [&](this auto&& calc3, ll x) -> ll {
        if (x <= n) return pre[x];
        if (x % 2 == 1)
            return pre[n];
        else
            return pre[n] ^ calc3(x / 2);
    };
    auto calc2 = [&](this auto&& calc2, ll x) -> ll {
        if (x <= n) return pre3[x];
        if (pre[n] == 0)
            return pre3[n] + calc2(x / 2) - calc2(n / 2);
        else
            return pre3[n] + (x / 2 - n / 2 - calc2(x / 2) + calc2(n / 2)) + (x - n) / 2;
    };
    auto calc = [&](this auto&& cacl, ll x) -> ll {
        if (x <= n) return pre2[x];
        return pre2[n] + 2 * (calc2(x / 2) - calc2(n / 2)) - (x % 2 == 0 ? 1 : 0) * calc3(x / 2);
    };
    cout << calc(r) - calc(l - 1) << endl;
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
