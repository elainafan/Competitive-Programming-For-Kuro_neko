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
using i128 = __int128_t;
void solve() {
    ll n, q, l, r, x;
    cin >> n >> q;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    vl pre(n + 1);
    rep(i, 1, n) pre[i] = pre[i - 1] + a[i - 1];
    const ll B = sqrt(n);
    vector<array<ll, 3>> queries;
    vl tem;
    rep(i, 0, q - 1) {
        cin >> l >> r >> x;
        l--, r--;
        queries.push_back({l, r, x});
        tem.push_back(x);
    }
    auto sorted = tem;
    ranges::sort(sorted);
    sorted.erase(unique(all(sorted)), sorted.end());
    int m = sz(sorted);
    vl id(q);
    rep(i, 0, q - 1) { id[i] = ranges::lower_bound(sorted, tem[i]) - sorted.begin(); }
    vvl up(B + 1, vl(m, -1));
    rep(i, 1, B) {
        int cnt = n - i;
        rep(j, 0, m - 1) {
            while (cnt >= 0 && pre[cnt + i] - pre[cnt] < sorted[j]) {
                cnt--;
            }
            if (cnt >= 0)
                up[i][j] = cnt;
            else
                break;
        }
    }
    rep(i, 0, q - 1) {
        auto [l, r, x] = queries[i];
        ll cur = l;
        ll cnt = 0, re = 0;
        rep(j, 1, B) {
            if (cur > up[j][id[i]]) continue;
            if (cur <= min(r - j + 1, up[j][id[i]])) {
                ll tem2 = (min(r - j + 1, up[j][id[i]]) - cur) / j + 1;
                cnt += tem2;
                cur += tem2 * j;
            }
        }
        while (cur <= r) {
            if (pre[r + 1] - pre[cur] < x) {
                re = pre[r + 1] - pre[cur];
                break;
            }
            cnt++;
            ll tem2 = lower_bound(pre.begin() + cur + 1, pre.begin() + r + 2, pre[cur] + x) - pre.begin();
            cur = tem2;
        }
        cout << cnt << ' ' << re << endl;
    }
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
