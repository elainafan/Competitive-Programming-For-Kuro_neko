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
string ask(ll l, ll r) {
    cout << "? " << l << ' ' << r << '\n';
    cout.flush();
    string op;
    cin >> op;
    return op;
}
void report(ll a) {
    cout << "! " << a << '\n';
    cout.flush();
}
void solve() {
    ll n;
    cin >> n;
    ll ans = 0;
    ll r = 0;
    rep(i, 1, n) {
        if (r < i) r = i;
        while (r <= n - 1) {
            string op = ask(i, r + 1);
            if (op == "Yes")
                r++;
            else
                break;
        }
        ans += r - i;
    }
    report(ans);
    return;
}
int main() {
    solve();
    return 0;
}