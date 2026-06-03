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
    string s, t;
    int n;
    cin >> n >> s >> t;
    ll cnt1 = 0, cnt2 = 0;
    ll tem1 = 0, tem2 = 0;
    ll tot = 0;
    rep(i, 0, n - 1) { tot += (s[i] == '(' ? 1 : -1) + (t[i] == '(' ? 1 : -1); }
    if (tot) {
        cout << "NO" << endl;
        return;
    }
    rep(i, 0, n - 1) {
        cnt1 += (s[i] == '(' ? 1 : -1), cnt2 += (t[i] == '(' ? 1 : -1);
        if (s[i] == '(' && t[i] == ')') tem1++;
        if (s[i] == ')' && t[i] == '(') tem2++;
        if (cnt1 < 0) {
            if (tem2 > 0) {
                tem2--;
                cnt1 += 2;
                cnt2 -= 2;
            }
            if (cnt2 < 0) {
                cout << "NO" << endl;
                return;
            }
        } else if (cnt2 < 0) {
            if (tem1 > 0) {
                tem1--;
                cnt2 += 2;
                cnt1 -= 2;
            }
            if (cnt1 < 0) {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
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
