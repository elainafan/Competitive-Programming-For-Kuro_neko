#include <bits/stdc++.h>
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
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define pq priority_queue
#define umap unordered_map
#define mset multiset
using namespace std;
void solve() {
    int n, k;
    cin >> n >> k;
    vi a(k);
    rep(i, 0, k - 1) cin >> a[i];
    vi b(n);
    rep(i, 0, n - 1) cin >> b[i];
    vvi ma(k);
    rep(i, 0, n - 1) {
        if (b[i] == k + 1) continue;
        ma[b[i] - 1].push_back(i);
    }
    vi res;
    frep(i, k - 1, 0) {
        for (int& p : ma[i]) {
            rep(j, 1, k - i) res.push_back(p + 1);
        }
    }
    cout << sz(res) << endl;
    rep(i, 0, sz(res) - 1) cout << res[i] << ' ';
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
