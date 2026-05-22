#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
#define rep(i, x, y) for (int i = (int)x; i <= (int)y; i++)
#define frep(i, x, y) for (int i = (int)x; i >= (int)y; i--)
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
#define endl '\n'
using namespace std;
void solve() {
    int n;
    cin >> n;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    ll ans = 0;
    ll tem = 0;
    rep(i, 0, n - 1) tem += a[i];
    vl suf(n + 1, INT_MAX);
    frep(i, n - 1, 0) suf[i] = min(suf[i + 1], a[i]);
    rep(i, 0, n - 1) ans += 1LL * suf[i];
    ll ans2 = ans;
    map<ll, ll> ma;
    rep(i, 0, n - 1) {
        if (ma.count(a[i])) ans2 = min(ans2, ans - ma[a[i]]);
        ma[suf[i]]++;
    }
    cout << tem - min(ans, ans2) << endl;
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
