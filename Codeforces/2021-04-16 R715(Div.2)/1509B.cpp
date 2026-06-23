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
    ll n;
    string s;
    cin >> n >> s;
    ll tem0 = 0, tem1 = 0, tem2 = 0;
    ll tot0 = 0, tot1 = 0;
    rep(i, 0, n - 1) {
        if (s[i] == 'T')
            tot0++;
        else
            tot1++;
    }
    if (tot0 != 2 * tot1) {
        cout << "NO" << endl;
        return;
    }
    int las = 0;
    rep(i, 0, n - 1) {
        if (s[i] == 'M') {
            las++;
            if (tem0 < las) {
                cout << "NO" << endl;
                return;
            }
        } else
            tem0++;
    }
    las = 0, tem0 = 0;
    frep(i, n - 1, 0) {
        if (s[i] == 'M') {
            las++;
            if (tem0 < las) {
                cout << "NO" << endl;
                return;
            }
        } else
            tem0++;
    }
    cout << "YES" << endl;
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
