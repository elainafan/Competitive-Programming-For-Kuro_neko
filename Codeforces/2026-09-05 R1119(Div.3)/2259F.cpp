#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
#define rep(i, x, y) for (ll i = x; i <= y; i++)
#define frep(i, x, y) for (ll i = x; i >= y; i--)
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
using namespace std;
using i128 = __int128_t;
void solve() {
    ll n;
    cin >> n;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    string s;
    cin >> s;
    ll tot = 0;
    ll tem = 0;
    rep(i, 0, n - 1) {
        if (a[i] == 1) {
            tem++;
            continue;
        } else {
            tot += tem;
        }
    }
    cout << tot << ' ';
    vl pre(n);
    rep(i, 0, n - 1) pre[i] = (i == 0 ? (a[i] == 0) : pre[i - 1] + (a[i] == 0));
    vl pos0, pos1;
    rep(i, 0, n - 1) {
        if (a[i] == 0)
            pos0.push_back(i);
        else
            pos1.push_back(i);
    }
    ll m1 = sz(pos0), m2 = sz(pos1);
    ll l = 0, r = sz(pos0) - 1;
    rep(i, 0, n - 1) {
        if (s[i] == '1' && l <= m2 - 1) {
            tot -= max(0LL, r + 1 - pre[pos1[l]]);
            l++;
        } else if (s[i] == '0' && r >= 0) {
            tot -= max(0LL, pos0[r] + 1 - pre[pos0[r]] - l);
            r--;
        }
        cout << tot << ' ';
    }
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
