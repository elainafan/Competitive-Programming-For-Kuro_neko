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
    int n;
    cin >> n;
    vector<pll> ma(n);
    vector<pair<char, char>> op(n);
    rep(i, 0, n - 1) { cin >> op[i].first >> ma[i].first >> op[i].second >> ma[i].second; }
    vector<pll> suf(n + 1);
    suf[n].first = suf[n].second = 1;
    frep(i, n - 1, 0) {
        suf[i] = suf[i + 1];
        if (op[i].first == 'x') suf[i].first += max(suf[i + 1].first, suf[i + 1].second) * (ma[i].first - 1);
        if (op[i].second == 'x') suf[i].second += max(suf[i + 1].first, suf[i + 1].second) * (ma[i].second - 1);
    }
    ll l = 1, r = 1;
    rep(i, 0, n - 1) {
        ll tem = 0;
        if (op[i].first == '+')
            tem += ma[i].first;
        else
            tem += (ma[i].first - 1) * l;
        if (op[i].second == '+')
            tem += ma[i].second;
        else
            tem += (ma[i].second - 1) * r;
        if (suf[i + 1].first >= suf[i + 1].second)
            l += tem;
        else
            r += tem;
    }
    cout << l + r << endl;
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
