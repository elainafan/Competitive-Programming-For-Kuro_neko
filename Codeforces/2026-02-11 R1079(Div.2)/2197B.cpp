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
    int n;
    cin >> n;
    vi p(n);
    vi a(n);
    rep(i, 0, n - 1) cin >> p[i];
    rep(i, 0, n - 1) cin >> a[i];
    vector<pair<int, int>> pos(n + 1, {INT_MAX, INT_MIN});
    vi cnt(n + 1);
    map<int, int> ma;
    rep(i, 0, n - 1) {
        pos[a[i]].first = min(pos[a[i]].first, i);
        pos[a[i]].second = max(pos[a[i]].second, i);
        cnt[a[i]]++;
        ma[p[i]] = i;
    }
    rep(i, 1, n) {
        if (pos[i] == make_pair(INT_MAX, INT_MIN)) continue;
        if (pos[i].second - pos[i].first + 1 != cnt[i]) {
            cout << "No" << endl;
            return;
        }
    }
    int l = 0;
    int r = 0;
    auto a2 = a;
    a2.erase(unique(all(a2)), a2.end());
    int m = sz(a2);
    rep(i, 0, m - 1) {
        if (ma[a2[i]] < l) {
            cout << "No" << endl;
            return;
        }
        l = max(l, ma[a2[i]]);
    }
    cout << "Yes" << endl;
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
