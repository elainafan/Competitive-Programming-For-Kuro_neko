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
    string s;
    cin >> s;
    int n = sz(s);
    string t;
    cin >> t;
    int m = sz(t);
    vi cnt;
    vi cnt2;
    int tem = 0;
    rep(i, 0, n - 1) {
        if (i > 0 && s[i] != s[i - 1]) {
            cnt.push_back(tem);
            tem = 1;
        } else
            tem++;
    }
    if (tem) {
        cnt.push_back(tem);
        tem = 0;
    }
    rep(i, 0, m - 1) {
        if (i > 0 && t[i] != t[i - 1]) {
            cnt2.push_back(tem);
            tem = 1;
        } else
            tem++;
    }
    if (tem) {
        cnt2.push_back(tem);
        tem = 0;
    }
    if (sz(cnt) != sz(cnt2)) {
        cout << "NO" << endl;
        return;
    }
    int ans = 0;
    int st = 0, st2 = 0;
    rep(i, 0, sz(cnt) - 1) {
        if (s[st] != t[st2]) {
            cout << "NO" << endl;
            return;
        }
        int x = cnt[i], y = cnt2[i];
        if (y > 2 * x || y < x) {
            cout << "NO" << endl;
            return;
        }
        st += x, st2 += y;
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
