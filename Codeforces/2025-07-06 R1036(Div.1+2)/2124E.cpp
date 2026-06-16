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
    ll tot = 0;
    rep(i, 0, n - 1) tot += a[i];
    if (tot % 2 == 1) {
        cout << -1 << endl;
        return;
    }
    ll maxx = *max_element(all(a));
    if (2 * maxx > tot) {
        cout << -1 << endl;
        return;
    }
    vvl res;
    vl premax1(n), premax2(n);
    vl preidx1(n), preidx2(n);
    premax1[0] = a[0], premax2[0] = LLONG_MIN;
    preidx1[0] = 0, preidx2[0] = -1;
    rep(i, 1, n - 1) {
        premax1[i] = premax1[i - 1], premax2[i] = premax2[i - 1];
        preidx1[i] = preidx1[i - 1], preidx2[i] = preidx2[i - 1];
        if (a[i] >= premax1[i]) {
            premax2[i] = premax1[i], preidx2[i] = preidx1[i];
            premax1[i] = a[i], preidx1[i] = i;
        } else if (a[i] >= premax2[i]) {
            premax2[i] = a[i], preidx2[i] = i;
        }
    }
    vl sufmax1(n), sufmax2(n);
    vl sufidx1(n), sufidx2(n);
    sufmax1[n - 1] = a[n - 1], sufmax2[n - 1] = LLONG_MIN;
    sufidx1[n - 1] = n - 1, sufidx2[n - 1] = -1;
    frep(i, n - 2, 0) {
        sufmax1[i] = sufmax1[i + 1], sufmax2[i] = sufmax2[i + 1];
        sufidx1[i] = sufidx1[i + 1], sufidx2[i] = sufidx2[i + 1];
        if (a[i] >= sufmax1[i]) {
            sufmax2[i] = sufmax1[i], sufidx2[i] = sufidx1[i];
            sufmax1[i] = a[i], sufidx1[i] = i;
        } else if (a[i] >= sufmax2[i]) {
            sufmax2[i] = a[i], sufidx2[i] = i;
        }
    }
    ll pre2 = 0;
    rep(i, 0, n - 2) {
        pre2 += a[i];
        ll tem = (pre2 - (tot - pre2));
        if (tem == 0) {
            cout << 1 << endl;
            rep(i, 0, n - 1) cout << a[i] << ' ';
            cout << endl;
            return;
        }
    }
    pre2 = 0;
    rep(i, 0, n - 2) {
        pre2 += a[i];
        ll tem = (pre2 - (tot - pre2));
        if (tem > 0 && tem % 2 == 0) {
            vl tem2 = a;
            int idx = -1;
            ll tem3 = tem / 2;
            vl tem4(n);
            rep(j, 0, i) {
                if (tem3 == 0) break;
                ll te = min(tem2[j], tem3);
                tem3 -= te;
                tem2[j] -= te;
                tem4[j] = te;
                idx = j;
            }
            tem3 = tem / 2;
            rep(j, idx + 1, i) {
                if (tem3 == 0) break;
                ll te = min(tem2[j], tem3);
                tem3 -= te;
                tem2[j] -= te;
                tem4[j] = te;
                idx = i;
            }
            res.push_back(tem2);
            res.push_back(tem4);
            break;
        }
    }
    if (res.empty()) {
        cout << -1 << endl;
        return;
    }
    cout << sz(res) << endl;
    rep(i, 0, sz(res) - 1) {
        for (auto& p : res[i]) cout << p << ' ';
        cout << endl;
    }
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
