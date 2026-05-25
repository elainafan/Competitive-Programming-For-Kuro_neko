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
    int n;
    cin >> n;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    vl b(n);
    rep(i, 0, n - 1) cin >> b[i];
    auto check = [&](int mid) -> bool {
        string res = "";
        auto upd = [&](char x) {
            res.push_back(x);
            if (res == "--" || res == "+++" || res == "++-" || res == "+--")
                res.pop_back();
            else if (res == "-+")
                res.clear();
            else if (res == "+-+") {
                res.pop_back();
                res.pop_back();
            }
        };
        rep(i, 0, n - 1) {
            int tem = (a[i] >= mid) + (b[i] >= mid);
            if (tem == 1) continue;
            if (tem == 0)
                upd('-');
            else
                upd('+');
        }
        return res == "+" || res == "++";
    };
    ll l = 1, r = 2 * n, mid, ans;
    while (l <= r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else
            r = mid - 1;
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