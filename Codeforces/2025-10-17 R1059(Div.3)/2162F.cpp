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
    ll n, m;
    cin >> n >> m;
    vector<pll> ma(m);
    rep(i, 0, m - 1) {
        cin >> ma[i].first >> ma[i].second;
        ma[i].first--, ma[i].second--;
    }
    ll mixx = LLONG_MIN, maxx = LLONG_MAX;
    rep(i, 0, m - 1) {
        mixx = max(mixx, ma[i].first);
        maxx = min(maxx, ma[i].second);
    }
    vl res(n);
    if (mixx <= maxx) {
        res[mixx] = 0;
        int idx = 1;
        rep(i, 0, n - 1) {
            if (i == mixx) continue;
            res[i] = idx++;
        }
        rep(i, 0, n - 1) cout << res[i] << ' ';
        cout << endl;
        return;
    }
    ll idx = -1;
    rep(i, 0, n - 2) {
        bool flag = false;
        rep(j, 0, m - 1) {
            if (ma[j].second == i) {
                flag = true;
            }
        }
        if (!flag) idx = i;
    }
    if (idx != -1) {
        res[idx] = 0;
        res[idx + 1] = 1;
        int idx2 = 2;
        rep(i, 0, n - 1) {
            if (i == idx || i == idx + 1) continue;
            res[i] = idx2++;
        }
        rep(i, 0, n - 1) cout << res[i] << ' ';
        cout << endl;
        return;
    }
    idx = -1;
    rep(i, 1, n - 1) {
        bool flag = false;
        rep(j, 0, m - 1) {
            if (ma[j].first == i) {
                flag = true;
            }
        }
        if (!flag) idx = i;
    }
    if (idx != -1) {
        res[idx] = 0;
        res[idx - 1] = 1;
        int idx2 = 2;
        rep(i, 0, n - 1) {
            if (i == idx || i == idx - 1) continue;
            res[i] = idx2++;
        }
        rep(i, 0, n - 1) cout << res[i] << ' ';
        cout << endl;
        return;
    }
    cout << 0 << ' ' << 2 << ' ' << 1 << ' ';
    rep(i, 3, n - 1) cout << i << ' ';
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
