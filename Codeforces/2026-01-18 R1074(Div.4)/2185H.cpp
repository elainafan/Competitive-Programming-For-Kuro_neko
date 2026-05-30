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
    ll n, k;
    cin >> n >> k;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    vl pre(n + 1);
    rep(i, 1, n) pre[i] = pre[i - 1] + a[i - 1];
    vl tem;
    rep(i, 0, n - 1) {
        if (a[i] > pre[i]) tem.push_back(i);
    }
    vl res(n);
    rep(i, 0, n - 1) {
        vl tem2;
        for (auto& p : tem) {
            if (p == i) continue;
            if (p < i) {
                if (a[p] > pre[p] + a[i]) tem2.push_back(p + 1);
            } else {
                tem2.push_back(p);
            }
        }
        ll l = 0, r = n - 1, mid, ans = -1;
        auto check = [&](ll mid) -> bool {
            ll tem = (mid <= i ? pre[mid] : pre[mid + 1] - a[i]);
            return tem < a[i];
        };
        while (l <= r) {
            mid = (l + r) / 2;
            if (check(mid)) {
                ans = mid;
                l = mid + 1;
            } else
                r = mid - 1;
        }
        int m = sz(tem2);
        l = 0, r = ans;
        if (l <= r) {
            ll tem4 = (m > k ? max(l, tem2[m - k - 1]) : l);
            res[i] += max(r - tem4 + 1, 0LL);
        }
        l = ans + 1, r = n - 1;
        if (l <= r && k >= 1) {
            ll tem4 = (m > k - 1 ? max(l, tem2[m - k]) : l);
            res[i] += max(r - tem4 + 1, 0LL);
        }
    }
    rep(i, 0, n - 1) cout << res[i] << ' ';
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
