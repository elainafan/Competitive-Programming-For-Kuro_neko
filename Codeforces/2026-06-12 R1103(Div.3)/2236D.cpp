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
    vector<pll> b;
    for (auto& [x, y] : ma) b.emplace_back(x, y);
    int m = sz(b);
    vl c(m);
    rep(i, 0, m - 1) c[i] = b[i].first;
    set<int> s;
    frep(i, m - 1, 0) {
        int tem = ranges::upper_bound(c, c[i] + k) - c.begin();
        auto x = s.lower_bound(i + 1);
        if (b[i].second % 2 == 0) {
            cout << "YES" << endl;
            return;
        } else {
            if (x != s.end() && (*x) < tem) {
                cout << "YES" << endl;
                return ;
            } else {
                s.insert(i);
            }
        }
    }
    cout << "NO" << endl;
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
