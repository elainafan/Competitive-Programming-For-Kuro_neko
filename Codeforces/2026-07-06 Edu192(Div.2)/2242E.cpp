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
    ll l, r, n;
    cin >> l >> r >> n;
    ll tem = 1;
    while ((tem << 1) <= r) tem <<= 1;
    if (l < tem) {
        ll x = max(l, tem >> 1);
        ll y = tem;
        string a, b;
        while (x) {
            a.push_back((char)('0' + (x % 2)));
            x /= 2;
        }
        ranges::reverse(a);
        while (y) {
            b.push_back((char)('0' + (y % 2)));
            y /= 2;
        }
        ranges::reverse(b);
        rep(i, 0, n - 1) {
            char tem1 = a[i % sz(a)], tem2 = b[i % sz(b)];
            cout << (tem1 == '1' && tem2 == '1' ? '1' : '0');
        }
        cout << endl;
        return;
    }
    ll tem2 = 0;
    ll x = l, y = r;
    while (x < y) {
        x >>= 1, y >>= 1;
        tem2++;
    }
    ll tem3 = x << tem2;
    string a;
    while (tem3) {
        a.push_back((char)('0' + (tem3 % 2)));
        tem3 /= 2;
    }
    ranges::reverse(a);
    rep(i, 0, n - 1) { cout << a[i % sz(a)]; }
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
