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
    vvi ma(3, vi(6));
    rep(i, 0, 2) { rep(j, 0, 5) cin >> ma[i][j]; }
    double ans = 0;
    vector<vector<double>> ma2(3, vector<double>(3));
    rep(i, 0, 2) {
        double tem = 0, tem2 = 0, tem3 = 0;
        rep(j, 0, 5) {
            tem += (ma[i][j] == 4) * (1.0 / 6.0);
            tem2 += (ma[i][j] == 5) * (1.0 / 6.0);
            tem3 += (ma[i][j] == 6) * (1.0 / 6.0);
        }
        ma2[i][0] = tem, ma2[i][1] = tem2, ma2[i][2] = tem3;
    }
    ans += ma2[0][0] * ma2[1][1] * ma2[2][2];
    ans += ma2[0][0] * ma2[1][2] * ma2[2][1];
    ans += ma2[0][1] * ma2[1][0] * ma2[2][2];
    ans += ma2[0][1] * ma2[1][2] * ma2[2][0];
    ans += ma2[0][2] * ma2[1][1] * ma2[2][0];
    ans += ma2[0][2] * ma2[1][0] * ma2[2][1];
    cout << ans << endl;
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}
