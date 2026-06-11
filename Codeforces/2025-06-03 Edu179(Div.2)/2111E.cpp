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
    ll n, q;
    cin >> n >> q;
    string s;
    char x, y;
    cin >> s;
    set<ll> ma[3][3];
    rep(i, 0, q - 1) {
        cin >> x >> y;
        ma[x - 'a'][y - 'a'].insert(i);
    }
    rep(i, 0, n - 1) {
        int tem = s[i] - 'a';
        if (!tem) continue;
        if (tem == 1) {
            if (!ma[1][0].empty()) {
                ma[1][0].erase(ma[1][0].begin());
                s[i] = 'a';
                continue;
            }
            if (!ma[1][2].empty() && !ma[2][0].empty()) {
                auto x = ma[2][0].upper_bound(*ma[1][2].begin());
                if (x != ma[2][0].end()) {
                    auto y = ma[1][2].lower_bound(*x);
                    --y;
                    ma[1][2].erase(y);
                    ma[2][0].erase(x);
                    s[i] = 'a';
                    continue;
                }
            }
        } else if (tem == 2) {
            if (!ma[2][0].empty()) {
                ma[2][0].erase(ma[2][0].begin());
                s[i] = 'a';
                continue;
            }
            if (!ma[2][1].empty() && !ma[1][0].empty()) {
                auto x = ma[1][0].upper_bound(*ma[2][1].begin());
                if (x != ma[1][0].end()) {
                    auto y = ma[2][1].lower_bound(*x);
                    --y;
                    ma[2][1].erase(y);
                    ma[1][0].erase(x);
                    s[i] = 'a';
                    continue;
                }
            }
            if (!ma[2][1].empty()) {
                ma[2][1].erase(ma[2][1].begin());
                s[i] = 'b';
                continue;
            }
        }
    }
    cout << s << endl;
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
