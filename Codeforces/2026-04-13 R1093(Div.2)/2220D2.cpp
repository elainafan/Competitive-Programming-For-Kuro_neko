#include <bits/stdc++.h>
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
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define pq priority_queue
#define umap unordered_map
#define mset multiset
using namespace std;
void ask(int l, vi res) {
    cout << "? " << l << ' ';
    rep(i, 0, l - 1) cout << res[i] << ' ';
    cout << endl;
    cout.flush();
}
void report(ll x, ll y, ll z) {
    cout << "! " << x << ' ' << y << ' ' << z << '\n';
    cout.flush();
}
void solve() {
    int n;
    cin >> n;
    int l = 1, r = 2 * n + 1, mid;
    ll x, y, z;
    int op;
    auto check = [&](vi& res) -> bool {
        int cnt = sz(res);
        ask(cnt, res);
        cin >> op;
        if ((cnt - op) % 2 == 1)
            return true;
        else
            return false;
    };
    while (l <= r) {
        mid = (l + r) / 2;
        vi tem;
        rep(i, 1, mid) tem.push_back(i);
        if (check(tem)) {
            r = mid - 1;
            x = mid;
        } else
            l = mid + 1;
    }
    l = 1, r = 2 * n + 1;
    while (l <= r) {
        mid = (l + r) / 2;
        vi tem;
        frep(i, 2 * n + 1, mid) tem.push_back(i);
        if (check(tem)) {
            y = mid;
            l = mid + 1;
        } else
            r = mid - 1;
    }
    l = y + 1, r = x - 1;
    while (l <= r) {
        mid = (l + r) / 2;
        vi tem;
        rep(i, 1, mid) tem.push_back(i);
        tem.push_back(x);
        if (check(tem)) {
            r = mid - 1;
            z = mid;
        } else
            l = mid + 1;
    }
    report(x, y, z);
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
