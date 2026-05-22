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
    ll n, x, y;
    cin >> n;
    vector<pll> ma(n);
    rep(i, 0, n - 1) {
        cin >> x >> y;
        ma[i].first = x + y;
        ma[i].second = x - y;
    }
    ranges::sort(ma);
    mset<ll> s;
    for (auto& [x, y] : ma) {
        auto it = s.upper_bound(y);
        if (it == s.begin()) {
            s.insert(y);
        } else {
            it--;
            s.erase(it);
            s.insert(y);
        }
    }
    cout << sz(s) << endl;
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}