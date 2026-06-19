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
    map<ll, ll> ma;
    rep(i, 0, n - 1) { ma[a[i]]++; }
    ll ans = n - sz(ma);
    ll l = -1, r = -1;
    ll ans2 = 0;
    int i = 0;
    int res = -1;
    while (i <= n - 1) {
        if (ma[a[i]] != 1) i++;
        int j = i;
        while (j <= n - 1 && ma[a[j]] == 1) j++;
        if (j - i > ans2) {
            ans2 = j - i;
            res = i;
        }
        i = j;
    }
    if (ans2 == 0)
        cout << 0 << endl;
    else
        cout << res + 1 << ' ' << res + ans2 << endl;
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
