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
int ask(int l, int r) {
    int op;
    cout << "? " << l << ' ' << r << '\n';
    cout.flush();
    cin >> op;
    return op;
}
void report(char sum) {
    cout << "! " << sum << '\n';
    cout.flush();
}
void solve() {
    int n;
    cin >> n;
    vi a(n);
    rep(i, 0, n - 1) {
        cin >> a[i];
        a[i]--;
    }
    vi cnt(n, -1);
    rep(i, 0, n - 1) { cnt[a[i]] = i; }
    int idx = -1;
    rep(i, 0, n - 1) {
        if (cnt[i] == -1) {
            idx = i;
            break;
        }
    }
    if (idx != -1) {
        int idx2 = -1;
        rep(i, 0, n - 1) {
            if (i == idx) continue;
            idx2 = i;
            break;
        }
        int op = ask(idx + 1, idx2 + 1);
        if (op == 0)
            report('A');
        else
            report('B');
        return;
    }
    int op = ask(cnt[0] + 1, cnt[n - 1] + 1);
    int op2 = ask(cnt[n - 1] + 1, cnt[0] + 1);
    if (op + op2 > n)
        report('B');
    else
        report('A');
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
