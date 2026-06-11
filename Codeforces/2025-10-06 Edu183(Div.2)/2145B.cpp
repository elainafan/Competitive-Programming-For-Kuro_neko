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
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vl a(n + 1, 1);
    int tem = 0;
    int l = 1, r = n;
    rep(i, 0, k - 1) {
        if (s[i] == '0') {
            a[l] = 0;
            l++;
        } else if (s[i] == '1') {
            a[r] = 0;
            r--;
        } else
            tem++;
    }
    if (r - l + 1 <= tem) {
        rep(i, 0, n - 1) cout << '-';
        cout << endl;
        return ;
    }
    rep(i, l, l + tem - 1) {
        if (a[i] == 0)
            continue;
        else
            a[i] = 2;
    }
    frep(i, r, r - tem + 1) {
        if (a[i] == 0)
            continue;
        else
            a[i] = 2;
    }
    rep(i, 1, n) {
        if (a[i] == 0)
            cout << '-';
        else if (a[i] == 1)
            cout << '+';
        else
            cout << '?';
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
