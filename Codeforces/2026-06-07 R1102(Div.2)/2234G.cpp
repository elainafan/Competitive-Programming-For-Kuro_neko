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
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    set<array<ll, 3>> s;
    vvl tem(n + 2);
    set<ll> win;
    rep(i, 0, n + 1) win.insert(i);
    rep(i, 0, n) s.insert({1, i, i + 1});
    rep(i, 1, n) {
        if (n - i - 1 >= 0) tem[n - i - 1].push_back(i);
    }
    frep(i, n - 1, 0) {
        for (auto& p : tem[i]) {
            win.erase(p);
            auto x = win.upper_bound(p);
            auto xx = x;
            xx--;
            s.erase({p - *xx, *xx, p});
            s.erase({*x - p, p, *x});
            s.insert({*x - *xx, *xx, *x});
        }
        while (!s.empty() && (*prev(s.end()))[0] >= a[i] + 2) {
            auto [len, l, r] = *prev(s.end());
            rep(j, l + 1, r - a[i] - 1) {
                if (i == 0 && j == 1) {
                    cout << 2 << endl;
                    return;
                }
                s.erase({r - j + 1, j - 1, r});
                s.insert({1, j - 1, j});
                s.insert({r - j, j, r});
                win.insert(j);
                if (i - j - 1 >= 0) tem[i - j - 1].push_back(j);
            }
        }
    }
    cout << 1 << endl;
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
