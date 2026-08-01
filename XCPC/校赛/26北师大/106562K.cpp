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
ll ask(ll l) {
    cout << "? " << l << '\n';
    cout.flush();
    ll op;
    cin >> op;
    return op;
}
void report(string s) {
    cout << "! " << s << '\n';
    cout.flush();
}
void solve() {
    ll l = 1, r = 1e9, mid;
    rep(i, 0, 99) {
        mid = (l + r) / 2;
        ll op = ask(mid);
        if (l == r) {
            if (op == 0) {
                report("wrong");
                return;
            }
        } else {
            if (op == 1)
                r = mid;
            else
                l = mid + 1;
        }
    }
    report("correct");
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