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
    ll n, m, q;
    cin >> n >> m >> q;
    string name, res;
    char pro;
    ll tim;
    vl passed(n), submit(n), seen(n, false), exploded(n, false);
    map<string, vl> havepassed;
    map<string, vl> havesubmit;
    rep(_, 0, q - 1) {
        cin >> name >> pro >> res >> tim;
        ll p = pro - 'A';
        if (!havesubmit.count(name)) havesubmit[name] = vl(n);
        if (!havepassed.count(name)) havepassed[name] = vl(n);
        if (!havesubmit[name][p]) havesubmit[name][p] = 1, submit[p]++;
        if (res == "AC" && !havepassed[name][p]) havepassed[name][p] = 1, passed[p]++;
        bool flag = (tim >= 240 || passed[p] >= 50 || (submit[p] > 0 && 5 * passed[p] >= submit[p]));
        if (flag)
            seen[p] = true;
        else if (seen[p])
            exploded[p] = true;
    }
    string ans = "";
    rep(i, 0, n - 1) {
        if (exploded[i]) ans.push_back((char)('A' + i));
    }
    cout << (ans == "" ? "-" : ans) << endl;
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
