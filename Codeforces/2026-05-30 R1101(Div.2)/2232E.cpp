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
#define endl '\n'
using namespace std;
constexpr ll MOD = 1e9 + 7;
ll mul(ll x, ll y) { return x * y % MOD; }
ll qpow(ll x, ll y) {
    ll z = 1;
    while (y > 0) {
        if (y & 1) z = mul(z, x);
        x = mul(x, x);
        y >>= 1;
    }
    return z;
}  // 求x**y%MOD

// 注意：当MOD为质数时， (x/y)%MOD=(x*(y**(MOD-2)))%MOD，即y在模MOD意义下的逆元为b^{-1} \equiv b^{p-2} mod p
void solve() {
    ll n, k;
    cin >> n >> k;
    vl l(k);
    vector<string> ma(k);
    vector<pll> ma2(k);
    rep(i, 0, k - 1) {
        cin >> l[i];
        l[i]--;
        cin >> ma2[i].first >> ma2[i].second;
        ma2[i].first--, ma2[i].second--;
        if (!l[i]) continue;
        cin >> ma[i];
    }
    vl cnt(n);
    vvl tem(n);
    rep(i, 0, k - 1) {
        cnt[l[i] / 2] = 1;
        tem[l[i] / 2].resize(l[i] / 2 + 1);
        ll x = ma2[i].first, y = ma2[i].second;
        rep(j, 0, l[i]) {
            ll tem2 = x + y;
            ll tem3 = abs(tem2 - (n - 1));
            ll tem4 = x - max(0LL, tem2 - (n - 1));
            tem[l[i] / 2][tem3] = tem4;
            if (j == l[i]) break;
            if (ma[i][j] == 'D')
                x++;
            else
                y++;
        }
    }
    ll ans = 1;
    frep(i, n - 1, 0) {
        ll l = 0, r = n - i - 1;
        if (cnt[i]) l = r = tem[i][i];
        rep(j, i + 1, n - 1) {
            if (!cnt[j]) continue;
            if (tem[j][i + 1] + 1 == tem[j][i])
                r = min(r, tem[j][i + 1]);
            else if (tem[j][i + 1] == tem[j][i])
                l = max(l, tem[j][i + 1] + 1);
        }
        ans = mul(ans, (r - l + 1));
    }
    cout << ans << endl;
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