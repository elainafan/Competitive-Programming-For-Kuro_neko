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
using i128 = __int128_t;
void solve() {
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int maxx = 0;
    int i = 0;
    while (i <= n - 1) {
        if (s[i] == '1') {
            int j = i;
            while (j <= n - 1 && s[j] == '1') j++;
            if (j - i >= k) {
                cout << "NO" << endl;
                return;
            }
            i = j;
        } else
            i++;
    }
    cout << "YES" << endl;
    vl res(n);
    vl tem;
    rep(i, 0, n - 1) {
        if (s[i] != '1') tem.push_back(i);
    }
    int las = n;
    for (auto& p : tem) res[p] = las--;
    rep(i, 0, n - 1) {
        if (!res[i]) res[i] = las--;
    }
    rep(i, 0, n - 1) cout << res[i] << ' ';
    cout << endl;
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
