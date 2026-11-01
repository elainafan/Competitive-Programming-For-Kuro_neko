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
void solve1() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll cnt0 = 0, cnt1 = 0;
    rep(i, 0, n - 1) {
        if (s[i] == '0')
            cnt0++;
        else
            cnt1++;
    }
    ll idx = 0;
    if (cnt0 < cnt1) idx = 1;
    string res = "";
    ll base = s[0] - '0';
    rep(i, 0, n - 1) {
        if (s[i] == '0' + idx) {
            if (i % 2 == 0)
                res.push_back((char)s[0]);
            else
                res.push_back((char)('0' + (base ^ 1)));
        } else {
            if (i % 2 == 0)
                res.push_back((char)s[0]), res.push_back((char)s[0]);
            else
                res.push_back((char)('0' + (base ^ 1))), res.push_back((char)('0' + (base ^ 1)));
        }
    }
    cout << sz(res) << endl;
    cout.flush();
    cout << res << endl;
    cout.flush();
    return;
}
void solve2() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vl tem;
    ll i = 0;
    while (i <= n - 1) {
        ll j = i;
        while (j <= n - 1 && s[j] == s[i]) j++;
        tem.push_back(j - i);
        i = j;
    }
    ll base = s[0] - '0';
    ll m = sz(tem);
    string res = "";
    rep(i, 0, m - 1) {
        if (tem[i] != tem[0])
            res.push_back((char('0' + (base ^ 1))));
        else
            res.push_back(s[0]);
    }
    cout << sz(res) << endl;
    cout.flush();
    cout << res << endl;
    cout.flush();
    return;
}
void solve() {
    int t, q;
    cin >> t >> q;
    while (t--) {
        if (q == 1)
            solve1();
        else
            solve2();
    }
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}
