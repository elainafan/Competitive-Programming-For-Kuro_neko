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
    ll n, m, k;
    cin >> n >> m >> k;
    vl a(m);
    rep(i, 0, m - 1) cin >> a[i];
    vl b(k);
    rep(i, 0, k - 1) cin >> b[i];
    string res = "";
    map<ll, ll> ma;
    rep(i, 0, k - 1) ma[b[i]]++;
    rep(i, 0, m - 1) {
        if (sz(ma) < n - 1)
            res.push_back('0');
        else if (sz(ma) == n)
            res.push_back('1');
        else if (ma.count(a[i]))
            res.push_back('0');
        else
            res.push_back('1');
    }
    cout << res << endl;
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
