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
    string s;
    cin >> n >> s;
    vvl pre(n, vl(26));
    vvl suf(n, vl(26));
    pre[0][s[0] - 'a']++;
    suf[n - 1][s[n - 1] - 'a']++;
    rep(i, 1, n - 1) {
        pre[i] = pre[i - 1];
        pre[i][s[i] - 'a']++;
    }
    frep(i, n - 2, 0) {
        suf[i] = suf[i + 1];
        suf[i][s[i] - 'a']++;
    }
    rep(i, 1, n - 2) {
        if (pre[i - 1][s[i] - 'a'] || suf[i + 1][s[i] - 'a']) {
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
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
