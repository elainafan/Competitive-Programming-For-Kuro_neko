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
    string s;
    cin >> s;
    int n = sz(s);
    vi cnt(26);
    rep(i, 0, n - 1) cnt[s[i] - 'a']++;
    int tem = *max_element(all(cnt));
    if (tem > (n + 1) / 2) {
        cout << "No" << endl;
        return;
    }
    priority_queue<pii, vector<pii>, less<>> q;
    rep(i, 0, 25) {
        if (cnt[i]) q.emplace(cnt[i], i);
    }
    cout << "Yes" << endl;
    string res = "";
    while (sz(q) >= 2) {
        auto [x1, y1] = q.top();
        q.pop();
        auto [x2, y2] = q.top();
        q.pop();
        res.push_back((char)('a' + y1));
        res.push_back((char)('a' + y2));
        if (x1 > 1) q.emplace(x1 - 1, y1);
        if (x2 > 1) q.emplace(x2 - 1, y2);
    }
    if (!q.empty()) res.push_back((char)(q.top().second + 'a'));
    cout << res << endl;
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
