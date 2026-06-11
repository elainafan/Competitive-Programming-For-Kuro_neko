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
    map<ll, vl> ma;
    rep(i, 0, n - 1) ma[a[i]].push_back(i);
    ll tem = 0;
    vl tem2;
    for (auto& [x, y] : ma) {
        if (y[sz(y) - 1] - y[0] + 1 != sz(y)) {
            tem++;
            tem2.push_back(x);
        }
    }
    if (tem == 0) {
        cout << "YES" << endl;
        return;
    }
    if (tem > 2) {
        cout << "NO" << endl;
        return;
    }
    set<pll> s;
    for (auto& p : tem2) {
        ll m = sz(ma[p]);
        if (ma[p][m - 1] - ma[p][1] + 1 <= m) {
            rep(i, 0, 1) {
                ll cnt = 0;
                ll idx = -1;
                if (i == 0) {
                    if (ma[p][1] + m - 1 >= n) continue;
                    rep(j, ma[p][1], ma[p][1] + m - 1) {
                        if (a[j] != p) {
                            cnt++;
                            idx = j;
                        }
                    }
                    if (cnt != 1 || idx == -1) continue;
                } else {
                    if (ma[p][m - 1] - m + 1 < 0) continue;
                    rep(j, ma[p][m - 1] - m + 1, ma[p][m - 1]) {
                        if (a[j] != p) {
                            cnt++;
                            idx = j;
                        }
                    }
                    if (cnt != 1 || idx == -1) continue;
                }
                s.insert(make_pair(min(ma[p][0], idx), max(ma[p][0], idx)));
            }
        }
        if (ma[p][m - 2] - ma[p][0] + 1 <= m) {
            rep(i, 0, 1) {
                ll cnt = 0;
                ll idx = -1;
                if (i == 0) {
                    if (ma[p][0] + m - 1 >= n) continue;
                    rep(j, ma[p][0], ma[p][0] + m - 1) {
                        if (a[j] != p) {
                            cnt++;
                            idx = j;
                        }
                    }
                    if (cnt != 1 || idx == -1) continue;
                } else {
                    if (ma[p][m - 2] - m + 1 < 0) continue;
                    rep(j, ma[p][m - 2] - m + 1, ma[p][m - 2]) {
                        if (a[j] != p) {
                            cnt++;
                            idx = j;
                        }
                    }
                    if (cnt != 1 || idx == -1) continue;
                }
                s.insert(make_pair(min(ma[p][m - 1], idx), max(ma[p][m - 1], idx)));
            }
        }
    }
    for (auto& [x, y] : s) {
        swap(a[x], a[y]);
        map<ll, ll> ma2;
        bool flag = true;
        rep(i, 0, n - 1) {
            if (i == 0 || a[i] != a[i - 1]) {
                if (ma2.count(a[i])) {
                    flag = false;
                    break;
                }
            }
            ma2[a[i]]++;
        }
        if (flag) {
            cout << "YES" << endl;
            return;
        }
        swap(a[x], a[y]);
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
