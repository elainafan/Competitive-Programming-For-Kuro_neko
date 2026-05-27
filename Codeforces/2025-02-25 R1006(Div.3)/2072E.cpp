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
void solve() {
    int k;
    cin >> k;
    vector<pii> ma;
    vl ma2;
    rep(i, 2, 499) ma2.emplace_back(i * (i - 1) / 2);
    int idx1 = 0, idx2 = 0;
    while (k > 0) {
        int tem2 = ranges::upper_bound(ma2, k) - ma2.begin() - 1;
        rep(i, 0, tem2 + 1) {
            ma.emplace_back(idx1, idx2);
            idx2++;
        }
        idx1++;
        k -= ma2[tem2];
    }
    cout << sz(ma) << endl;
    for (auto& p : ma) cout << p.first << ' ' << p.second << endl;
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
