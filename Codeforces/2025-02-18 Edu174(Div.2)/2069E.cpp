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
#define endl '\n'
using namespace std;
void solve() {
    string s;
    cin >> s;
    int n = sz(s);
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    int cnt0 = 0, cnt1 = 0;
    rep(i, 0, n - 1) {
        if (s[i] == 'A')
            cnt0++;
        else
            cnt1++;
    }
    if (a + b + 2 * c + 2 * d < n) {
        cout << "NO" << endl;
        return;
    }
    vi tem;
    vi tem2;
    ll tem3 = 0;
    int l = 0;
    while (l <= n - 1) {
        int r = l;
        while (r < n - 1 && s[r + 1] != s[r]) r++;
        if ((r - l + 1) % 2 == 1) {
            tem3 += (r - l + 1) / 2;
        } else {
            if (s[l] == 'A')
                tem.push_back((r - l + 1) / 2);
            else
                tem2.push_back((r - l + 1) / 2);
        }
        l = r + 1;
    }
    ranges::sort(tem);
    ranges::sort(tem2);
    ll re = 0;
    rep(i, 0, sz(tem) - 1) {
        if (c >= tem[i]) {
            c -= tem[i];
            re += tem[i];
        } else
            tem3 += tem[i] - 1;
    }
    rep(i, 0, sz(tem2) - 1) {
        if (d >= tem2[i]) {
            d -= tem2[i];
            re += tem2[i];
        } else
            tem3 += tem2[i] - 1;
    }
    re += min(tem3, c + d);
    if (a + re >= cnt0 && b + re >= cnt1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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