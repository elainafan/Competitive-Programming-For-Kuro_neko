#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
#define rep(i, x, y) for (int i = (int)x; i <= (int)y; i++)
#define frep(i, x, y) for (int i = (int)x; i >= (int)y; i--)
#define all(x) (x).begin(), (x).end()
#define all2(x) (x).rbegin(), (x).rend()
#define sz(a) (int)a.size()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define tri tuple<int, int, int>
#define trl tuple<ll, ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define pq priority_queue
#define umap unordered_map
#define endl '\n'
using namespace std;
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vl a(n + 1);
    rep(i, 1, n) cin >> a[i];
    vl c(n + 1);
    vl b(n + 1);
    rep(i, 1, n) cin >> c[i];
    vector<pll> ma(n + 1);
    rep(i, 1, n - 1) {
        if (c[i + 1] < c[i]) {
            cout << "No" << endl;
            return;
        }
    }
    if (s[0] == '1') {
        if (a[1] != c[1]) {
            cout << "No" << endl;
            return;
        }
    }
    ma[1].first = ma[1].second = c[1];
    rep(i, 2, n) {
        ll l, r;
        if (c[i] == c[i - 1]) {
            l = LLONG_MIN / 3;
            r = c[i];
        } else {
            l = c[i];
            r = c[i];
        }
        if (s[i - 1] == '1') {
            ma[i].first = max(ma[i - 1].first + a[i], l);
            ma[i].second = min(ma[i - 1].second + a[i], r);
        } else {
            ma[i].first = l;
            ma[i].second = r;
        }
    }
    rep(i, 1, n) {
        if (ma[i].first > ma[i].second) {
            cout << "No" << endl;
            return;
        }
    }
    b[n] = ma[n].second;
    frep(i, n, 1) {
        if (s[i - 1] == '1') {
            b[i - 1] = b[i] - a[i];
        } else
            b[i - 1] = ma[i - 1].second;
    }
    frep(i, n, 1) a[i] = b[i] - b[i - 1];
    cout << "Yes" << endl;
    rep(i, 1, n) cout << a[i] << ' ';
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