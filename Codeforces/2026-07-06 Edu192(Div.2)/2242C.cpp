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
    ll n, k;
    cin >> n >> k;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    map<ll, ll> ma;
    rep(i, 0, n - 1) ma[a[i]]++;
    vl tem;
    for (auto& [x, y] : ma) tem.push_back(y);
    ranges::sort(tem);
    ll maxx = *max_element(all(tem));
    ll ans = 0;
    int m = sz(tem);
    vl suf(m);
    suf[m - 1] = tem[m - 1];
    frep(i, m - 2, 0) suf[i] = suf[i + 1] + tem[i];
    int i = 0;
    while (i <= m - 1) {
        int j = i;
        while (j <= m - 1 && tem[i] == tem[j]) j++;
        ll tem2 = k - suf[i];
        if (tem2 % (m - i) == 0 && (tem[i] + (tem2 / (m - i))) > 0) ans++;
        i = j;
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
