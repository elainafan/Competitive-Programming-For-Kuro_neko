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
    ll n, m;
    string s;
    cin >> n >> m >> s;
    vl a(m);
    rep(i, 0, m - 1) cin >> a[i];
    set<ll> s1;
    rep(i, 0, m - 1) s1.insert(a[i]);
    int cur = 1;
    rep(i, 0, n - 1) {
        if (s[i] == 'A') {
            cur++;
            s1.insert(cur);
        } else {
            cur++;
            while (s1.count(cur)) cur++;
            s1.insert(cur);
            cur++;
            while (s1.count(cur)) cur++;
        }
    }
    cout << sz(s1) << endl;
    for (auto& p : s1) cout << p << ' ';
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
