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
    int n;
    cin >> n;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    int idx1 = -1, idx2 = -1;
    int maxx = INT_MIN;
    rep(i, 0, n - 1) {
        int tem = 0;
        int tem2 = 0;
        rep(j, i, n - 1) {
            tem += (a[j] < a[i]);
            tem2 += (a[j] > a[i]);
            if (tem - tem2 > maxx) {
                idx1 = i, idx2 = j;
                maxx = tem - tem2;
            }
        }
    }
    cout << idx1 + 1 << ' ' << idx2 + 1 << endl;
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
