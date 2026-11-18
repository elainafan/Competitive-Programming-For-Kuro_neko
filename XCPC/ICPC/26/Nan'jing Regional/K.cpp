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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
constexpr ll INF = LLONG_MAX / 3;
constexpr ll MOD = 998244353;
void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vl res(n);
    ll ptr = 0;
    rep(i, 0, n - 1) {
        vl a, id(10);
        rep(j, 0, 9) {
            id[j] = sz(a);
            ll val = (s[ptr] == 'X' ? 10 : s[ptr] - '0');
            ptr++;
            a.push_back(val);
            if (j < 9) {
                if (val != 10) {
                    ll val2 = (s[ptr] == '/' ? 10 - val : s[ptr] - '0');
                    ptr++;
                    a.push_back(val2);
                }
            } else {
                if (val == 10) {
                    ll val2 = (s[ptr] == 'X' ? 10 : s[ptr] - '0');
                    ptr++;
                    a.push_back(val2);
                    ll val3;
                    if (s[ptr] == 'X')
                        val3 = 10;
                    else if (s[ptr] == '/')
                        val3 = 10 - val2;
                    else
                        val3 = s[ptr] - '0';
                    ptr++;
                    a.push_back(val3);
                } else {
                    ll val2 = (s[ptr] == '/' ? 10 - val : s[ptr] - '0');
                    ptr++;
                    a.push_back(val2);
                    if (val + val2 == 10) {
                        ll val3 = (s[ptr] == 'X' ? 10 : s[ptr] - '0');
                        ptr++;
                        a.push_back(val3);
                    }
                }
            }
        }
        ll ans = 0;
        rep(j, 0, 8) {
            ll st = id[j];
            if (a[st] == 10) {
                ans += 10 + a[st + 1] + a[st + 2];
            } else {
                if (a[st] + a[st + 1] == 10)
                    ans += 10 + a[st + 2];
                else
                    ans += a[st] + a[st + 1];
            }
        }
        rep(j, id[9], sz(a) - 1) ans += a[j];
        res[i] = ans;
    }
    rep(i, 0, n - 1) cout << res[i] << ' ';
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
