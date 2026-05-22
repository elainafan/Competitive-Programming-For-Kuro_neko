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
#define trl tuple<ll, ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define pq priority_queue
#define umap unordered_map
#define endl '\n'
using namespace std;

ull splitmix64(ull x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
}

struct custom_hash {
    static const ull FIXED_RANDOM;

    size_t operator()(ull x) const { return splitmix64(x + FIXED_RANDOM); }
};

const ull custom_hash::FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
void solve() {
    int n;
    cin >> n;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    vector<pii> tem3;
    rep(i, 0, n - 1) {
        if (a[i] == 1) {
            tem3.emplace_back(1, 0);
            tem3.emplace_back(2, 1);
            continue;
        }
        ll tem = a[i];
        ll tem2 = 0;
        while (tem != 1) {
            tem3.emplace_back(tem, tem2);
            if (tem % 2 == 0)
                tem /= 2;
            else
                tem++;
            tem2++;
        }
        tem3.emplace_back(tem, tem2);
    }
    ll ans = LLONG_MAX;
    int m = sz(tem3);
    sort(all(tem3));
    int i = 0;
    while (i < m) {
        ll tem2 = 0;
        int j = i;
        while (j < m && tem3[j].first == tem3[i].first) {
            tem2 += tem3[j].second;
            j++;
        }
        if (j == i + n) ans = min(ans, tem2);
        i = j;
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