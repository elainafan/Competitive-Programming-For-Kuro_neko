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
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    auto check = [&](ll l, ll r) -> vl {
        vl cnt(62);
        while (l < r) {
            ll tem;
            if (l == 0) {
                tem = 63 - __builtin_clzll(r);
                tem = (1LL << tem);
            } else {
                tem = lowbit(l);
                while (tem > r - l) tem >>= 1;
            }
            cnt[__builtin_ctzll(tem)]++;
            l += tem;
        }
        return cnt;
    };
    vl cnt1 = check(a, b);
    vl cnt2 = check(c, d);
    ll ans = 0;
    rep(i, 0, 61) {
        rep(j, 0, 61) { ans += cnt1[i] * cnt2[j] * (1LL << (abs(j - i))); }
    }
    cout << ans << endl;
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
