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
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int ask(int l, int r, int v) {
    int op;
    cout << "? " << l << ' ' << r << ' ' << v << '\n';
    cout.flush();
    cin >> op;
    return op;
}
void report(int l, int r, int v) {
    cout << "! " << l << ' ' << r << ' ' << v << '\n';
    cout.flush();
}
void solve() {
    int n;
    cin >> n;
    int x = 1, y = 2, z = 3;
    while (true) {
        int tem = rng() % 3;
        int op = ask(x, y, z);
        if (op == 0) {
            report(x, y, z);
            return ;
        }
        if (tem == 0)
            x = op;
        else if (tem == 1)
            y = op;
        else
            z = op;
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
