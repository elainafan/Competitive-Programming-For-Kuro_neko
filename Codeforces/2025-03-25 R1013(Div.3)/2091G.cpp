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
#define vb vector<bool>
#define pq priority_queue
#define umap unordered_map
#define mset multiset
using namespace std;
void solve() {
    ll s, k;
    cin >> s >> k;
    if (s % k == 0) {
        cout << k << endl;
        return;
    }
    if (s > k * k) {
        cout << max(1LL, k - 2) << endl;
        return;
    }
    vb vis1(s + 5, false), vis2(s + 5, false);
    vis1[k] = 1;
    int tem = 1;
    while (true) {
        queue<int> q;
        rep(i, 0, s - 1) {
            if (vis1[i]) q.push(i);
        }
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            int tem2 = x + tem * k;
            if (tem2 >= 0 && tem2 <= s && !vis1[tem2]) {
                vis1[tem2] = true;
                q.push(tem2);
            }
        }
        if (vis1[s]) {
            cout << k << endl;
            return;
        }
        k = max(k - 1, 1LL);
        tem = -tem;
        ranges::fill(vis2, false);
        rep(i, 0, s - 1) {
            if (vis1[i] && i + tem * k >= 0 && i + tem * k <= s) {
                vis2[i + tem * k] = true;
            }
        }
        swap(vis1, vis2);
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
