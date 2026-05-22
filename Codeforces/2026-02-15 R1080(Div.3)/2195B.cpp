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
void solve() {
    int n;
    cin >> n;
    vi a(n + 1);
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) {
        vi temp;
        for (int j = i; j <= n; j *= 2) {
            temp.push_back(a[j]);
        }
        ranges::sort(temp);
        int cnt = 0;
        for (int j = i; j <= n; j *= 2) {
            a[j] = temp[cnt];
            cnt++;
        }
    }
    bool flag = true;
    rep(i, 1, n - 1) {
        if (a[i] > a[i + 1]) {
            flag = false;
            break;
        }
    }
    if (!flag)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
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
