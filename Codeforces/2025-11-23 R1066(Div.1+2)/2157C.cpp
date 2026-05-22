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
    int n, k, q;
    int c, l, r;
    cin >> n >> k >> q;
    vector<set<int>> ma(n);
    vi a(n, 1e9);
    rep(i, 0, q - 1) {
        cin >> c >> l >> r;
        l--, r--;
        rep(j, l, r) ma[j].insert(c);
    }
    int cnt = 0;
    rep(i, 0, n - 1) {
        if (ma[i].count(1) && !ma[i].count(2)) {
            a[i] = k;
        }
        if (!ma[i].count(1) && ma[i].count(2)) {
            a[i] = cnt;
            cnt = (cnt + 1) % k;
        }
    }
    rep(i, 0, n - 1) cout << a[i] << ' ';
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
