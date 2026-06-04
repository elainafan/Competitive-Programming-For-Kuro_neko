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
ll ask(ll op2, ll l, ll r) {
    cout << op2 << ' ' << l << ' ' << r << '\n';
    cout.flush();
    ll op;
    cin >> op;
    return op;
}
void report(ll a, ll b) {
    cout << "! " << a << ' ' << b << '\n';
    cout.flush();
}
void solve() {
    ll n;
    cin >> n;
    ll tem = ask(2, 1, n) - ask(1, 1, n);
    ll l = 1, r = n, ans = 1, mid;
    auto check = [&](ll mid) -> bool { return ask(2, 1, mid) - ask(1, 1, mid) >= tem; };
    while (l <= r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else
            l = mid + 1;
    }
    report(ans - tem + 1, ans);
    return;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}