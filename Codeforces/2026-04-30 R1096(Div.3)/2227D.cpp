#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
#define rep(i, x, y) for (int i = (int)x; i <= (int)y; i++)
#define frep(i, x, y) for (int i = (int)x; i >= (int)y; i--)
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
#define endl '\n'
using namespace std;
void solve() {
    int n;
    cin >> n;
    vl a(2 * n);
    rep(i, 0, 2 * n - 1) cin >> a[i];
    int idx = -1, idx2 = -1;
    rep(i, 0, 2 * n - 1) {
        if (a[i] == 0) {
            if (idx == -1)
                idx = i;
            else
                idx2 = i;
        }
    }
    int l = idx + 1, r = idx2 - 1;
    bool flag = true;
    while (l <= r) {
        if (a[l] != a[r]) {
            flag = false;
            break;
        }
        l++, r--;
    }
    map<int, int> ma;
    l = idx - 1, r = idx2 + 1;
    while (l >= 0 && r <= 2 * n - 1) {
        if (a[l] == a[r]) {
            ma[a[l]]++;
            l--, r++;
        } else
            break;
    }
    rep(i, idx, idx2) { ma[a[i]]++; }
    int ans = 0;
    if (flag) {
        while (ma.count(ans)) ans++;
    }
    int ans2 = 0;
    ma.clear();
    l = idx, r = idx;
    while (l >= 0 && r <= 2 * n - 1) {
        if (a[l] == a[r]) {
            ma[a[l]]++;
            l--, r++;
        } else
            break;
    }
    while (ma.count(ans2)) ans2++;
    ma.clear();
    int ans3 = 0;
    l = idx2, r = idx2;
    while (l >= 0 && r <= 2 * n - 1) {
        if (a[l] == a[r]) {
            ma[a[l]]++;
            l--, r++;
        } else
            break;
    }
    while (ma.count(ans3)) ans3++;
    cout << max({ans, ans2, ans3}) << endl;
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
