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
void solve1() {
    ll n, s, x, y;
    cin >> n >> s;
    s--;
    vl a(n + 1);
    rep(i, 2, n) {
        if (s >> (i - 2) & 1)
            a[i] = a[i - 1] ^ 1;
        else
            a[i] = a[i - 1];
    }
    rep(i, 1, n - 1) {
        cin >> x >> y;
        if (a[x] == a[y])
            cout << x << ' ' << y << endl;
        else
            cout << y << ' ' << x << endl;
        cout.flush();
    }
    return;
}
void solve2() {
    ll n, x, y;
    cin >> n;
    vector<vector<pll>> ma(n + 1);
    rep(i, 1, n - 1) {
        cin >> x >> y;
        ma[x].emplace_back(y, (x > y));
        ma[y].emplace_back(x, (x > y));
    }
    vl a(n + 1, -1);
    a[1] = 0;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        for (auto& [x, y] : ma[node]) {
            if (a[x] == -1) {
                a[x] = a[node] ^ y;
                q.push(x);
            }
        }
    }
    ll s = 0;
    rep(i, 2, n) s += (a[i] ^ a[i - 1]) * (1LL << (i - 2));
    cout << s + 1 << endl;
    cout.flush();
    return;
}
void solve() {
    int t, q;
    cin >> t >> q;
    while (t--) {
        if (q == 1)
            solve1();
        else
            solve2();
    }
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}
