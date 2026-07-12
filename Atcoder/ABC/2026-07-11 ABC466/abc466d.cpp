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
    ll n, m;
    cin >> n >> m;
    vl vis1(n), vis2(n);
    vector<pll> ma(m);
    rep(i, 0, m - 1) cin >> ma[i].first >> ma[i].second, ma[i].first--, ma[i].second--;
    ll ans = 0;
    frep(i, m - 1, 0) {
        if (vis1[ma[i].first] == 0 && vis2[ma[i].second] == 0) ans++;
        vis1[ma[i].first] = 1, vis2[ma[i].second] = 1;
    }
    cout << ans << endl;
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}
