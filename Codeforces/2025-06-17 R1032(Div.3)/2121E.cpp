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
    string num1, num2;
    cin >> num1 >> num2;
    int n = num2.length();
    int dif = n - num1.length();
    map<pair<int, int>, ll> ma;
    auto dfs = [&](this auto&& dfs, int cnt, int s, bool limit_low, bool limit_high) -> int {
        if (cnt == n) return s;
        if (!limit_low && !limit_high && ma.count({cnt, s})) return ma[{cnt, s}];
        int res = INT_MAX;
        int lo = limit_low && cnt >= dif ? num1[cnt - dif] - '0' : 0;
        int hi = limit_high ? num2[cnt] - '0' : 9;
        int d = lo;
        for (; d <= hi; d++) {
            int tem = 0;
            if (cnt >= dif && d == num1[cnt - dif] - '0') tem++;
            if (d == num2[cnt] - '0') tem++;
            res = min(res, dfs(cnt + 1, s + tem, limit_low && d == lo, limit_high && d == hi));
        }
        if (!limit_high && !limit_low) ma[{cnt, s}] = res;
        return res;
    };
    cout << dfs(0, 0, true, true) << endl;
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
