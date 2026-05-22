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
    ll n, k;
    cin >> n >> k;
    vvl ma(n, vl(n));
    rep(i, 0, n - 1) { rep(j, 0, n - 1) cin >> ma[i][j]; }
    int tem = 0;
    rep(i, 0, n - 1) {
        rep(j, 0, n - 1) {
            if ((i + j) % 2 == 0) continue;
            tem ^= ma[i][j] % (k + 1);
        }
    }
    if (tem != 0)
        cout << "Alice" << endl;
    else
        cout << "Bob" << endl;
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