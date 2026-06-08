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
    ll n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    vl pre(n);
    pre[0] = (t[0] == '0' ? -1 : 1);
    rep(i, 1, n - 1) { pre[i] = pre[i - 1] + (t[i] == '0' ? -1 : 1); }
    ranges::sort(pre);
    vl pre2(n);
    pre2[0] = pre[0];
    rep(i, 1, n - 1) pre2[i] = pre2[i - 1] + pre[i];
    ll ans = 0;
    ll tem = 0;
    rep(i, 0, n - 1) {
        tem += (s[i] == '0' ? 1 : -1);
        ll tem2 = ranges::lower_bound(pre, tem) - pre.begin();
        ans += tem * tem2 - (tem2 > 0 ? pre2[tem2 - 1] : 0);
        ans += (tem2 > 0 ? pre2[n - 1] - pre2[tem2 - 1] : pre2[n - 1]) - (n - tem2) * tem;
    }
    cout << (n * n * (n + 1) - ans) / 2 << endl;
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
