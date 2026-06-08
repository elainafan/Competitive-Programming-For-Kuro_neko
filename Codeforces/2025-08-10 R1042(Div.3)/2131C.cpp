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
    vl a(n), b(n);
    rep(i, 0, n - 1) cin >> a[i];
    rep(i, 0, n - 1) cin >> b[i];
    map<ll, ll> ma;
    rep(i, 0, n - 1) {
        int tem = a[i] % k, tem2 = k - a[i] % k;
        ma[min(tem, tem2)]++;
    }
    map<ll, ll> ma2;
    rep(i, 0, n - 1) {
        int tem = b[i] % k, tem2 = k - b[i] % k;
        ma2[min(tem, tem2)]++;
    }
    for (auto& [x, y] : ma) {
        if (!ma2.count(x) || ma2[x] != y) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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
