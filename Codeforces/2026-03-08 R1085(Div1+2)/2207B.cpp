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
    int n, m, l;
    cin >> n >> m >> l;
    vi a(n);
    rep(i, 0, n - 1) cin >> a[i];
    vl d(m);
    int l1 = 0, r = 1e9, mid;
    int ans = -1;
    vi tem;
    int res = 0;
    rep(i, 0, n - 1) {
        if (i == 0) {
            if (a[i] == 1)
                continue;
            else
                tem.push_back(a[i]);
            continue;
        }
        tem.push_back(a[i] - a[i - 1]);
    }
    if (a[n - 1] != l) res = l - a[n - 1];
    int m1 = sz(tem);
    auto check = [&](int mid) -> bool {
        fill(all(d), 0LL);
        int maxx = 0;
        rep(i, 0, m1 - 1) {
            int tem2 = m1 - i + 1;
            if (tem2 >= m) {
                sort(all(d));
                ll te = tem[i];
                rep(j, 1, m) {
                    ll diff = (j == m) ? 0 : (d[j] - d[j - 1]);
                    ll cnt = diff * j;
                    if (j < m && te >= cnt) {
                        te -= cnt;
                    } else {
                        ll tem3 = d[j - 1] + te / j;
                        ll re = te % j;
                        rep(v, 0, j - 1) { d[v] = tem3 + (v >= j - re ? 1 : 0); }
                        break;
                    }
                }
                sort(all2(d));
                d[0] = 0;
            } else {
                sort(all2(d));
                sort(d.begin(), d.begin() + tem2);
                ll te = tem[i];
                rep(j, 1, tem2) {
                    ll diff = (j == tem2) ? 0 : (d[j] - d[j - 1]);
                    ll cnt = diff * j;
                    if (j < tem2 && te >= cnt) {
                        te -= cnt;
                    } else {
                        ll tem3 = d[j - 1] + te / j;
                        ll re = te % j;
                        rep(v, 0, j - 1) { d[v] = tem3 + (v >= j - re ? 1 : 0); }
                        break;
                    }
                }
                sort(all2(d));
                d[0] = 0;
            }
        }
        sort(all2(d));
        return d[0] + res <= mid;
    };
    while (l1 <= r) {
        mid = (l1 + r) / 2;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else
            l1 = mid + 1;
    }
    cout << ans << endl;
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
