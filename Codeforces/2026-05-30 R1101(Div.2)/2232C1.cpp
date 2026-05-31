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
void solve() {
    ll n, x, s;
    cin >> n >> x >> s;
    string t;
    cin >> t;
    ll cnt = 0;
    ll tem = 0;
    ll cur = 0;
    ll ans = 0;
    rep(i, 0, n - 1) {
        if (t[i] == 'I') {
            if (cnt == x) continue;
            cnt++;
            tem += s - 1;
            ans++;
        } else if (t[i] == 'A') {
            if (tem > 0) {
                tem--;
                cur++;
                ans++;
            } else if (cnt < x) {
                cnt++;
                tem += s - 1;
                ans++;
            }
        } else {
            if (tem > 0) {
                tem--;
                ans++;
            } else if (cnt < x && cur > 0) {
                cur--;
                cnt++;
                tem += s - 1;
                ans++;
            }
        }
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