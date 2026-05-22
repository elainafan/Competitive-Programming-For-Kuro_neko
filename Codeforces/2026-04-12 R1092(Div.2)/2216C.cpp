#include <bits/stdc++.h>
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
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define pq priority_queue
#define umap unordered_map
#define mset multiset
using namespace std;
void solve() {
    ll k, n, p, q;
    cin >> n >> k >> p >> q;
    if (p < q) swap(p, q);
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    if (p == q) {
        ll ans = 0;
        rep(i, 0, n - 1) ans += a[i] % p;
        cout << ans << endl;
        return;
    }
    vi tem(n);
    ll ans = 0;
    rep(i, 0, n - 1) {
        int tem2 = (a[i] % p) % q;
        int tem3 = (a[i] % q);
        if (tem2 < tem3)
            tem[i] = 1;
        else if (tem2 > tem3)
            tem[i] = 0;
        else
            tem[i] = 2;
        ans += 1LL * min(tem2, tem3);
    }
    int las = -1;
    int tem3 = 0;
    vi tem2;
    rep(i, 0, n - 1) {
        if (tem[i] == 0) {
            if (i != 0 && (tem[i - 1] == 1 || tem[i - 1] == 2)) {
                tem2.push_back(tem3);
                tem3 = 0;
            }
        } else
            tem3++;
    }
    if (tem3 != 0) tem2.push_back(tem3);
    if (!tem2.empty() && *max_element(all(tem2)) >= k) {
        cout << ans << endl;
        return;
    }
    tem2.clear();
    tem3 = 0;
    rep(i, 0, n - 1) {
        if (tem[i] == 1) {
            if (i != 0 && (tem[i - 1] == 0 || tem[i - 1] == 2)) {
                tem2.push_back(tem3);
                tem3 = 0;
            }
        } else
            tem3++;
    }
    if (tem3 != 0) tem2.push_back(tem3);
    if (!tem2.empty() && *max_element(all(tem2)) >= k) {
        cout << ans << endl;
        return;
    }
    ll cnt0 = 0, cnt1 = 0, cnt2 = 0;
    vl tem4;
    rep(i, 0, n - 1) {
        cnt0 += (a[i] % p) % q;
        cnt1 += a[i] % q;
        cnt2 += min((a[i] % p) % q, a[i] % q);
        if (i < k - 1) continue;
        tem4.push_back(ans + min(cnt0, cnt1) - cnt2);
        cnt0 -= a[i - k + 1] % p % q;
        cnt1 -= a[i - k + 1] % q;
        cnt2 -= min(a[i - k + 1] % p % q, a[i - k + 1] % q);
    }
    cout << *min_element(all(tem4)) << endl;
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
