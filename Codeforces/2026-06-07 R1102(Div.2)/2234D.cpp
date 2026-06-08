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
    ll n, k;
    cin >> n >> k;
    string s, t;
    cin >> s >> t;
    string tem;
    rep(i, 0, n - 1) tem.push_back('0');
    auto calc = [&](string s, string t) -> ll {
        ll ans = 0;
        rep(i, 0, n - 1) { ans += (s[i] != t[i]); }
        return ans;
    };
    ll tems = calc(s, tem);
    ll temt = calc(t, tem);
    ll temm = calc(s, t);
    if (k % 2 == 1)
        cout << ((1LL << k) + 1) / 3 * (tems * (n - tems) + temt * (n - temt) + temm * (n - temm)) << endl;
    else
        cout << ((1LL << k) + 2) / 3 * (tems * (n - tems) + temt * (n - temt)) + ((1LL << k) - 1) / 3 * temm * (n - temm) << endl;
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
