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
ll ask(ll k, vl& res) {
    cout << "? " << k << ' ';
    rep(i, 0, k - 1) cout << res[i] << ' ';
    cout.flush();
    ll op;
    cin >> op;
    return op;
}
void report(string s) {
    cout << "! " << s << '\n';
    cout.flush();
}
void solve() {
    ll n;
    cin >> n;
    vector<char> res(n);
    string res2 = "";
    ll l = 1, r = n - 1, mid, ans = -1;
    auto check = [&](ll mid) -> bool {
        vl tem;
        rep(i, 0, mid) tem.push_back(i + 1);
        ll op = ask(sz(tem), tem);
        return op > 0;
    };
    while (l <= r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            r = mid - 1;
            ans = mid;
        } else
            l = mid + 1;
    }

    ll idx1 = (ans == -1 ? 0 : ans), idx2 = (ans == -1 ? n - 1 : ans - 1);
    res[idx1] = ')', res[idx2] = '(';
    vl re;
    rep(i, 0, n - 1) {
        if (i == idx1 || i == idx2) continue;
        re.push_back(i + 1);
    }
    int m = sz(re);
    vl cnt = {2, 3, 4, 6, 7, 9, 10, 12, 18, 25, 35, 50};
    vl add = {2, 9, 20, 54, 77, 135, 170, 252, 594, 1175, 2345, 5000};
    ll tem = 574;
    map<ll, ll> ma;
    rep(i, 0, (1LL << 12) - 1) {
        ll tem2 = tem;
        rep(j, 0, 11) {
            if (i >> j & 1) tem2 += add[j];
        }
        ma[tem2] = i;
    }
    for (int i = 0; i <= m - 1; i += 12) {
        vl tem2(12, idx2 + 1);
        rep(j, 0, 11) {
            if (i + j <= m - 1) tem2[j] = re[i + j];
        }
        vl tem3;
        rep(j, 0, 11) {
            rep(v, 1, cnt[j]) {
                tem3.push_back(idx2 + 1);
                tem3.push_back(idx1 + 1);
                tem3.push_back(idx2 + 1);
                tem3.push_back(tem2[j]);
            }
            if (j != 11) {
                rep(v, 1, 2 * cnt[j] + 1) { tem3.push_back(idx1 + 1); }
            }
        }
        ll op = ask(sz(tem3), tem3);
        rep(j, 0, 11) {
            if (i + j >= m) continue;
            if (ma[op] >> j & 1)
                res[re[i + j] - 1] = ')';
            else
                res[re[i + j] - 1] = '(';
        }
    }
    rep(i, 0, n - 1) res2.push_back(res[i]);
    report(res2);
    return;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}