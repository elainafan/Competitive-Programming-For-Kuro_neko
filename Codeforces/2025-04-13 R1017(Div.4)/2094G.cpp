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
    ll q, op, x;
    cin >> q;
    ll tot = 0;
    ll len = 0;
    ll res = 0;
    deque<ll> d;
    bool flag = false;
    rep(i, 0, q - 1) {
        cin >> op;
        if (op == 1) {
            ll tem;
            if (!flag) {
                tem = d.back();
                d.pop_back();
                d.push_front(tem);
            } else {
                tem = d.front();
                d.pop_front();
                d.push_back(tem);
            }
            res = res + tot - len * tem;
            cout << res << endl;
        } else if (op == 2) {
            res = tot * (len + 1) - res;
            flag = (flag ? false : true);
            cout << res << endl;
        } else {
            cin >> x;
            len++;
            tot += x;
            res += x * len;
            if (!flag)
                d.push_back(x);
            else
                d.push_front(x);
            cout << res << endl;
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
