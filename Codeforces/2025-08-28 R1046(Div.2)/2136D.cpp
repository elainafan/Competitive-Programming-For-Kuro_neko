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
char dx[4] = {'U', 'L', 'D', 'R'};
ll ask(ll l, ll r) {
    cout << "? " << dx[l] << ' ' << r << '\n';
    cout.flush();
    ll op;
    cin >> op;
    return op;
}
void report(ll a, ll b) {
    cout << "! " << a << ' ' << b << ' ' << '\n';
    cout.flush();
}
void solve() {
    ll n;
    cin >> n;
    vector<pll> ma(n);
    ll maxx1 = LLONG_MIN, maxx2 = LLONG_MIN;
    rep(i, 0, n - 1) {
        cin >> ma[i].first >> ma[i].second;
        maxx1 = max(maxx1, ma[i].first + ma[i].second);
        maxx2 = max(maxx2, ma[i].second - ma[i].first);
    }
    const ll INF = 1e9;
    ll op = ask(0, INF);
    op = ask(0, INF);
    op = ask(3, INF);
    op = ask(3, INF);
    ll op2 = ask(1, INF);
    op2 = ask(1, INF);
    op2 = ask(1, INF);
    op2 = ask(1, INF);
    ll x, y;
    x = (op + maxx1 - op2 - maxx2) / 2, y = (op + op2 + maxx1 + maxx2 - 8LL * INF) / 2;
    report(x, y);
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