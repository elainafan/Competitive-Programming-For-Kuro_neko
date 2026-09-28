#include <bits/stdc++.h>
#define ll long long
#define rep(i, x, y) for (ll i = x; i <= y; i++)
#define frep(i, x, y) for (ll i = x; i >= y; i--)
#define all(x) (x).begin(), (x).end()
#define all2(x) (x).rbegin(), (x).rend()
#define sz(a) (int)a.size()
#define pll pair<ll, ll>
#define trl tuple<ll, ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vvl vector<vector<ll>>
using namespace std;
using i128 = __int128_t;
void solve() {
    ll n, q, x;
    cin >> n >> q;
    string s;
    cin >> s;
    ll tot = 0;
    ll cnt0 = 0, cnt1 = 0;
    rep(i, 0, n - 1) {
        if (i >= 1 && s[i] != s[i - 1]) tot += i * (n - i);
        if (s[i] == '0')
            cnt0++;
        else
            cnt1++;
    }
    cout << (tot + cnt0 * cnt1) / 2 << ' ';
    rep(_, 0, q - 1) {
        cin >> x;
        x--;
        if (x >= 1) tot += (s[x] == s[x - 1] ? x * (n - x) : x * (x - n));
        if (x <= n - 2) tot += (s[x] == s[x + 1] ? (x + 1) * (n - x - 1) : (x + 1) * (x + 1 - n));
        if (s[x] == '0')
            cnt0--, cnt1++, s[x] = '1';
        else
            cnt0++, cnt1--, s[x] = '0';
        cout << (tot + cnt0 * cnt1) / 2 << ' ';
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
