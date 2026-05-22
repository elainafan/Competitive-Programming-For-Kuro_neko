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
    ll n, m, q, x, y;
    cin >> n >> m;
    vector<pll> ma(m);
    map<ll, vector<pll>> ma1;
    map<ll, vector<pll>> ma2;
    map<pll, ll> ma3;
    rep(i, 0, m - 1) {
        cin >> ma[i].first >> ma[i].second;
        ma1[ma[i].first].emplace_back(ma[i].second, i + 1);
        ma2[ma[i].second].emplace_back(ma[i].first, i + 1);
        ma3[ma[i]]++;
    }
    for (auto& [x, y] : ma1) ranges::sort(y);
    for (auto& [x, y] : ma2) ranges::sort(y);
    ranges::sort(ma);
    vl suf1(m + 1, LLONG_MAX), suf2(m + 1, LLONG_MAX);
    frep(i, m - 1, 0) {
        suf1[i] = suf1[i + 1];
        suf2[i] = suf2[i + 1];
        if (ma[i].second <= suf1[i]) {
            suf2[i] = suf1[i];
            suf1[i] = ma[i].second;
        } else if (ma[i].second < suf2[i])
            suf2[i] = ma[i].second;
    }
    cin >> q;
    rep(i, 0, q - 1) {
        cin >> x >> y;
        vector<pll> tem;
        vector<pll> tem2;
        bool flag = false;
        if (ma1.count(x)) {
            auto it = ranges::upper_bound(ma1[x], make_pair(y, LLONG_MAX));
            while (it != ma1[x].begin() && sz(tem) < 2) {
                it--;
                tem.push_back(*it);
            }
        }
        if (ma2.count(y)) {
            auto it = ranges::lower_bound(ma2[y], make_pair(x, -1));
            while (it != ma2[y].end() && sz(tem2) < 2) {
                tem2.push_back(*it);
                it++;
            }
        }
        for (auto& [p, idx1] : tem) {
            for (auto& [q, idx2] : tem2) {
                if (idx1 == idx2) continue;
                if (q <= p + 1) {
                    cout << "Yes" << endl;
                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }
        if (flag) continue;
        if (ma3.count({x, y})) {
            int tem3 = ranges::lower_bound(ma, make_pair(x, -1)) - ma.begin();
            if (tem3 < m && suf2[tem3] <= y) {
                cout << "Yes" << endl;
                flag = true;
                continue;
            }
        }
        if (!flag) cout << "No" << endl;
    }
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}