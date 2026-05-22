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
    int n, k;
    cin >> n >> k;
    vector<string> ma(k);
    rep(i, 0, k - 1) cin >> ma[i];
    vi ma2(n);
    rep(i, 0, k - 1) { rep(j, 0, n - 1) ma2[j] |= (1 << (ma[i][j] - 'a')); }
    string ans = "";
    vector<int> d;
    auto init = [&](int x) -> void {
        for (int i = 1; i * i <= x; i++) {
            if (x % i == 0) {
                d.push_back(i);
                d.push_back(n / i);
            }
        }
        return;
    };
    init(n);
    ranges::sort(d);
    int m = sz(d);
    int res = 0;
    rep(i, 0, m - 1) {
        int val = d[i];
        bool flag = true;
        for (int j = 0; j <= val - 1; j++) {
            int tem = INT_MAX;
            for (int v = j; v <= n - 1; v += val) {
                tem &= ma2[v];
            }
            if (tem == 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            for (int j = 0; j <= val - 1; j++) {
                int tem = INT_MAX;
                for (int v = j; v <= n - 1; v += val) {
                    tem &= ma2[v];
                }
                rep(v, 0, 25) {
                    if ((tem >> v) & 1) {
                        ans += (char)('a' + v);
                        break;
                    }
                }
            }
            int res = n / d[i];
            string tem2 = ans;
            rep(i, 1, res - 1) ans += tem2;
            break;
        }
    }
    cout << ans << endl;
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
