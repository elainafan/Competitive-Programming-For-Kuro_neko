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
    ll h, w, k;
    cin >> h >> w >> k;
    vector<string> ma(h);
    rep(i, 0, h - 1) cin >> ma[i];
    ll ans = 0;
    vl cnt(h * w + 1);
    vl tem3;
    rep(i, 0, h - 1) {
        vl tem(w);
        rep(j, i, h - 1) {
            tem3.clear();
            rep(v, 0, w - 1) tem[v] += ma[j][v] - '0';
            cnt[0]++;
            tem3.push_back(0);
            ll tem2 = 0;
            rep(v, 0, w - 1) {
                tem2 += tem[v];
                if (tem2 >= k) ans += cnt[tem2 - k];
                if (cnt[tem2] == 0) tem3.push_back(tem2);
                cnt[tem2]++;
            }
            for (auto& p : tem3) cnt[p] = 0;
        }
    }
    cout << ans << endl;
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}
