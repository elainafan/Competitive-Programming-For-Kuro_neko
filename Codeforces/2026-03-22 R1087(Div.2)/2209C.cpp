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
void ask(int l, int r) {
    cout << "? " << l << ' ' << r << '\n';
    cout.flush();
}
void report(ll sum) {
    cout << "! " << sum << '\n';
    cout.flush();
}
void solve() {
    int n;
    cin >> n;
    vi a(2 * n);
    int op;
    ask(1, 2);
    cin >> op;
    if (op == 1) {
        report(1);
        return;
    }
    ask(2, 3);
    cin >> op;
    if (op == 1) {
        report(2);
        return;
    }
    ask(1, 3);
    cin >> op;
    if (op == 1) {
        report(3);
        return;
    }
    for (int i = 5; i <= 2 * n; i += 2) {
        ask(i, i + 1);
        cin >> op;
        if (op == 1) {
            report(i);
            return;
        }
    }
    report(4);
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
