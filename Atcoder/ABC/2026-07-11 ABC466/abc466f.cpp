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
    ll n, x;
    cin >> n >> x;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    ll las = LLONG_MAX;
    vl b;
    rep(i, 0, n - 1) {
        if (a[i] < las) {
            las = a[i];
            b.push_back(a[i]);
        }
    }
    int m = sz(b);
    vl tem(m);
    auto calc = [&](ll p, ll l) -> ll {
        ll ans = 0;
        while (l > 0) {
            ll l1 = p, r1 = m - 1, ans2 = m, mid;
            auto check = [&](ll mid) -> bool { return b[mid] < l; };
            while (l1 <= r1) {
                mid = (l1 + r1) / 2;
                if (check(mid)) {
                    ans2 = mid;
                    r1 = mid - 1;
                } else
                    l1 = mid + 1;
            }
            if (ans2 == m) return ans + 1;
            ans += l / b[ans2] * tem[ans2];
            l %= b[ans2];
            p = ans2 + 1;
        }
        return ans;
    };
    frep(i, m - 1, 0) tem[i] = calc(i + 1, b[i]);
    cout << calc(0, x + 1) - 1 << endl;
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
