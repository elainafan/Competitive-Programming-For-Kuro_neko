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
const ll MOD = 998244353;
void solve() {
    ll n;
    string s;
    cin >> n >> s;
    vvl ma(n);
    vl pa(n);
    rep(i, 1, n - 1) {
        cin >> pa[i];
        pa[i]--;
        ma[pa[i]].push_back(i);
        ma[i].push_back(pa[i]);
    }
    ll ans = 0;
    auto dfs = [&](this auto&& dfs, int x, int pa) -> array<ll, 4> {
        ll cnta = (s[x] == 'a'), cnte = (s[x] == 'e');
        ll cntb = 0, cntd = 0;
        ll tot = 0;
        for (auto& p : ma[x]) {
            if (p == pa) continue;
            auto [suba, sube, subb, subd] = dfs(p, x);
            cnta = (cnta + suba) % MOD, cnte = (cnte + sube) % MOD;
            cntb = (cntb + subb) % MOD, cntd = (cntd + subd) % MOD;
            tot = (tot + subb * subd) % MOD;
        }
        if (s[x] == 'c') ans = (ans + cntb * cntd % MOD - tot % MOD + MOD) % MOD;
        if (s[x] == 'b') cntb = (cntb + cnta) % MOD;
        if (s[x] == 'd') cntd = (cntd + cnte) % MOD;
        return {cnta, cnte, cntb, cntd};
    };
    dfs(0, -1);
    cout << ans << endl;
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    // int t;
    // cin >> t;
    // while (t--) {
    solve();
    //}
    return 0;
}
