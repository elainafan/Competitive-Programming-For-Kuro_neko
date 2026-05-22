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
    vi l(n);
    vvi a(n);
    rep(i, 0, n - 1) {
        cin >> l[i];
        a[i].resize(l[i]);
        rep(j, 0, l[i] - 1) cin >> a[i][j];
    }
    vi res;
    set<int> s;
    deque<int> d;
    vector<bool> vis(n, false);
    rep(i, 0, n - 1) {
        vi tem;
        vi tem2;
        int idx = -1;
        rep(j, 0, n - 1) {
            if (vis[j]) continue;
            tem.clear();
            set<int> s1;
            frep(v, sz(a[j]) - 1, 0) {
                if (s.count(a[j][v]) || s1.count(a[j][v])) continue;
                tem.push_back(a[j][v]);
                s1.insert(a[j][v]);
            }
            if (tem.empty()) continue;
            if (tem2.empty() || tem < tem2) {
                tem2 = tem;
                idx = j;
            }
        }
        if (idx == -1) break;
        vis[idx] = true;
        rep(j, 0, sz(tem2) - 1) {
            if (!s.count(tem2[j])) {
                d.push_back(tem2[j]);
                s.insert(tem2[j]);
            }
        }
    }
    while (!d.empty()) {
        auto node = d.front();
        d.pop_front();
        res.push_back(node);
    }
    for (int& p : res) cout << p << ' ';
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
