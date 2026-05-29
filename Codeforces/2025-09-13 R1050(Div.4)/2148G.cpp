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
constexpr int MX = 2e5 + 5;
vector<int> divisors[MX];
auto init = [] {
    for (int i = 1; i < MX; i++) {
        for (int j = i; j < MX; j += i) {
            divisors[j].push_back(i);
        }
    }
    return 0;
}();
void solve() {
    ll n;
    cin >> n;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    vl ma(n + 1);
    vl res(n);
    int tem = 0;
    rep(i, 0, n - 1) {
        if (i > 0) res[i] = res[i - 1];
        int tem2;
        if (tem == 0) {
            tem = a[i];
            tem2 = a[i];
        } else
            tem2 = __gcd(1LL * tem, a[i]);
        if (tem2 < tem) {
            res[i] = max(res[i], 1LL * i);
        }
        tem = tem2;
        for (auto& p : divisors[a[i]]) {
            ma[p]++;
            if (ma[p] < i + 1) res[i] = max(res[i], ma[p]);
        }
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
