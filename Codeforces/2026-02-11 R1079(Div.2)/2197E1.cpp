#include <bits/stdc++.h>
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
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define pq priority_queue
#define umap unordered_map
#define mset multiset
using namespace std;
vi ask(int l) {
    cout << "? " << l << '\n';
    cout.flush();
    int q;
    cin >> q;
    vi res(q);
    rep(i, 0, q - 1) cin >> res[i];
    return res;
}
void report(vector<pii> &res) {
    cout << "! " << sz(res) << '\n';
    rep(i, 0, sz(res) - 1) { cout << res[i].first << ' ' << res[i].second << '\n'; }
    cout.flush();
}
void solve() {
    int n;
    cin >> n;
    vector<pii> res;
    rep(i, 0, n - 1) {
        int las = -1;
        while (true) {
            int l = 1, r = (1 << 30), mid;
            int ans = r;
            while (l <= r) {
                mid = (l + r) / 2;
                vi tem = ask(mid);
                if (tem.empty())
                    r = mid - 1;
                else if (sz(tem) == 1 && tem[0] > i + 1)
                    r = mid - 1;
                else if (sz(tem) == 1 && tem[0] <= i + 1)
                    l = mid + 1;
                else if (sz(tem) >= 2) {
                    if (tem[0] < i + 1)
                        l = mid + 1;
                    else if (tem[0] > i + 1)
                        r = mid - 1;
                    else if (tem[0] == i + 1) {
                        if (tem[1] > las) {
                            r = mid - 1;
                            ans = mid;
                        } else
                            l = mid + 1;
                    }
                }
            }
            vi tem = ask(ans);
            if (sz(tem) <= 1) break;
            res.emplace_back(tem[0], tem[1]);
            las = tem[1];
        }
    }
    report(res);
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
