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
    cin >> n;
    string s;
    cin >> s;
    int idx1 = -1;
    rep(i, 0, n - 1) {
        if (s[i] == '0')
            continue;
        else {
            idx1 = i;
            break;
        }
    }
    if (idx1 == -1) {
        cout << "Bob" << endl;
        return;
    }
    int idx2 = n;
    frep(i, n - 1, 0) {
        if (s[i] == '1')
            continue;
        else {
            idx2 = i;
            break;
        }
    }
    if (idx2 == n || idx2 < idx1) {
        cout << "Bob" << endl;
        return;
    }
    string tem = s.substr(idx1, idx2 - idx1 + 1);
    if (sz(tem) % 2 == 1) {
        cout << "Alice" << endl;
        return;
    }
    int m = sz(tem);
    for (ll i = 0; i <= m - 1; i += 2) {
        if (tem[i] == tem[i + 1]) continue;
        cout << "Alice" << endl;
        return;
    }
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
