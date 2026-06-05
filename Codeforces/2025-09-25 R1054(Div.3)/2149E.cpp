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
    ll n, k, l, r;
    cin >> n >> k >> l >> r;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    ll l1 = 0, l2 = 0;
    map<ll, ll> ma;
    ll ans = 0, ans2 = 0;
    rep(r1, 0, n - 1) {
        ma[a[r1]]++;
        while (sz(ma) > k) {
            if (--ma[a[l1]] == 0) ma.erase(ma.find(a[l1]));
            l1++;
        }
        ll tem = max(l1, r1 - r + 1);
        ll tem2 = r1 - l + 1;
        if (tem <= tem2) ans += tem2 - tem + 1;
    }
    ma.clear();
    rep(r2, 0, n - 1) {
        ma[a[r2]]++;
        while (sz(ma) > k - 1) {
            if (--ma[a[l2]] == 0) ma.erase(ma.find(a[l2]));
            l2++;
        }
        ll tem = max(l2, r2 - r + 1);
        ll tem2 = r2 - l + 1;
        if (tem <= tem2) ans2 += tem2 - tem + 1;
    }
    cout << ans - ans2 << endl;
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
