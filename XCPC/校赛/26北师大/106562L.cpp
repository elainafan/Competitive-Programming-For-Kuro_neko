#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
#define rep(i, x, y) for (ll i = x; i <= y; i++)
#define frep(i, x, y) for (ll i = x; i >= y; i--)
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
using namespace std;
using i128 = __int128_t;
using ld = long double;
void solve() {
    char c;
    string s;
    ll q, op, k, p;
    cin >> s >> q;
    vector<tuple<ll, ll, char>> ma;
    ll tot = 0;
    rep(i, 0, q - 1) {
        cin >> op;
        if (op == 1) {
            cin >> c;
            ma.emplace_back(1, 0, c);
        } else if (op == 2) {
            cin >> k;
            ma.emplace_back(2, k, 'a');
            tot += k;
        } else {
            ma.emplace_back(3, 0, 'a');
        }
    }
    cin >> p;
    vl tem(q + 1);
    tem[0] = sz(s);
    ll cnt = 1;
    rep(i, 0, q - 1) {
        auto [x, y, z] = ma[i];
        if (x == 1) {
            tem[i + 1] = min(tem[i] + 1, p + tot);
        } else if (x == 2) {
            tem[i + 1] = max(tem[i] - y, 0LL);
        } else {
            tem[i + 1] = min(tem[i] * 2, p + tot);
        }
    }
    ll cur = p;
    frep(i, q - 1, 0) {
        auto [x, y, z] = ma[i];
        if (x == 1) {
            if (cur == tem[i] + 1) {
                cout << z << endl;
                return;
            }
        } else if (x == 3) {
            if (cur > tem[i]) cur -= tem[i];
        }
    }
    assert(cur >= 1 && cur <= sz(s));
    cout << s[cur - 1] << endl;
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
