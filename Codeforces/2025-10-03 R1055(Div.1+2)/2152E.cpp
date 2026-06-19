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
vl ask(ll k, vl& res) {
    cout << "? " << k << ' ';
    rep(i, 0, k - 1) cout << res[i] << ' ';
    cout << '\n';
    cout.flush();
    ll op;
    cin >> op;
    vl res2(op);
    rep(i, 0, op - 1) cin >> res2[i];
    return res2;
}
void report(vl& res) {
    cout << "! ";
    rep(i, 0, sz(res) - 1) cout << res[i] << ' ';
    cout << '\n';
    cout.flush();
}
void solve() {
    ll n;
    cin >> n;
    vl tem;
    rep(i, 1, n * n + 1) tem.push_back(i);
    vl pa(n * n + 5);
    rep(i, 1, n) {
        vl op = ask(sz(tem), tem);
        if (sz(op) >= n + 1) {
            vl res;
            rep(i, 0, n) res.push_back(op[i]);
            report(res);
            return;
        }
        int m = sz(op);
        int l = 0, las = 0;
        for (auto& p : tem) {
            if (l <= m - 1 && op[l] == p)
                las = p, l++;
            else
                pa[p] = las;
        }
        map<ll, ll> ma;
        rep(i, 0, m - 1) ma[op[i]]++;
        vl ntem;
        for (auto& p : tem) {
            if (ma.count(p)) continue;
            ntem.push_back(p);
        }
        tem = ntem;
    }
    vl res;
    ll tem2 = tem[0];
    rep(i, 0, n) {
        res.push_back(tem2);
        tem2 = pa[tem2];
    }
    ranges::reverse(res);
    report(res);
    return;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}