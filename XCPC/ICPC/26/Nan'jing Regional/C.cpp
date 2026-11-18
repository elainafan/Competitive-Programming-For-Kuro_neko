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
    ll n, m, k;
    cin >> n >> m >> k;
    vector<array<ll, 3>> ma(k);
    rep(i, 0, k - 1) cin >> ma[i][0] >> ma[i][1] >> ma[i][2], ma[i][0]--, ma[i][1]--;
    if (n == 1 && m == 1) {
        cout << 0 << endl;
        return;
    }
    if (n == 1) {
        ll cnt0 = 0, cnt1 = 0;
        rep(i, 0, k - 1) {
            if (ma[i][1] != 0 && ma[i][1] != m - 1) {
                cout << -1 << endl;
                return;
            }
        }
        rep(i, 0, k - 1) {
            if (ma[i][1] == 0)
                cnt0++;
            else
                cnt1++;
        }
        cout << abs(cnt0 - cnt1) << endl;
        return;
    }
    if (m == 1) {
        ll cnt0 = 0, cnt1 = 0;
        rep(i, 0, k - 1) {
            if (ma[i][0] != 0 && ma[i][0] != n - 1) {
                cout << -1 << endl;
                return;
            }
        }
        rep(i, 0, k - 1) {
            if (ma[i][0] == 0)
                cnt0++;
            else
                cnt1++;
        }
        cout << abs(cnt0 - cnt1) << endl;
        return;
    }
    vvl cnt(2, vl(2));
    rep(i, 0, k - 1) {
        if (ma[i][0] == 0 && ma[i][1] == 0)
            cnt[0][0]++;
        else if (ma[i][0] == 0 && ma[i][1] == m - 1)
            cnt[0][1]++;
        else if (ma[i][0] == n - 1 && ma[i][1] == 0)
            cnt[1][0]++;
        else if (ma[i][0] == n - 1 && ma[i][1] == m - 1)
            cnt[1][1]++;
        else {
            cout << -1 << endl;
            return;
        }
    }
    cout << abs(cnt[0][0] - cnt[1][1]) + abs(cnt[1][0] - cnt[0][1]) << endl;
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
