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
void solve() {
    ll n;
    cin >> n;
    auto check = [&](ll x) -> bool {
        while (x > 0) {
            if (x % 10 == 7) return true;
            x = x / 10;
        }
        return false;
    };
    if (check(n)) {
        cout << 0 << endl;
        return;
    }
    vl cnt(10);
    cnt[0] = 9;
    rep(i, 1, 9) { cnt[i] = cnt[i - 1] * 10 + 9; }
    rep(i, 1, 9) {
        rep(j, 0, 9) {
            ll tem = n;
            if (check(tem + cnt[j] * i)) {
                cout << i << endl;
                return;
            }
        }
    }
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
