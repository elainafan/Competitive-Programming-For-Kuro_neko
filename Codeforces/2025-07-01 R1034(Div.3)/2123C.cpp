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
    ll n;
    cin >> n;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    vl pre(n);
    vl suf(n);
    pre[0] = a[0], suf[n - 1] = a[n - 1];
    rep(i, 1, n - 1) pre[i] = min(pre[i - 1], a[i]);
    frep(i, n - 2, 0) suf[i] = max(suf[i + 1], a[i]);
    string res;
    rep(i, 0, n - 1) {
        if (i == 0) {
            res.push_back('1');
        } else if (i == n - 1) {
            res.push_back('1');
        } else {
            ll tem = pre[i - 1], tem2 = suf[i + 1];
            if (a[i] <= tem || a[i] >= tem2)
                res.push_back('1');
            else
                res.push_back('0');
        }
    }
    cout << res << endl;
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
