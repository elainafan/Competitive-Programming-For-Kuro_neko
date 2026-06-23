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
    if (ans == -1) {
        res[n - 1] = '(', res[0] = ')';
        vl re;
        rep(i, 1, n - 2) { re.push_back(i); }
        int m = sz(re);
        for (int i = 0; i < m - 1; i += 2) {
            vl tem;
            tem.push_back(n), tem.push_back(n);
            tem.push_back(re[i] + 1), tem.push_back(re[i + 1] + 1);
            tem.push_back(re[i] + 1);
            ll op = ask(sz(tem), tem);
            if (op == 0) {
                res[re[i]] = '(', res[re[i + 1]] = '(';
            } else if (op == 1) {
                res[re[i]] = '(', res[re[i + 1]] = ')';
            } else if (op == 2) {
                res[re[i]] = ')', res[re[i + 1]] = ')';
            } else {
                res[re[i]] = ')', res[re[i + 1]] = '(';
            }
        }
        if (m % 2 == 1) {
            vl tem;
            tem.push_back(n);
            tem.push_back(re[m - 1] + 1);
            ll op = ask(sz(tem), tem);
            if (op == 1)
                res[re[m - 1]] = ')';
            else
                res[re[m - 1]] = '(';
        }
        rep(i, 0, n - 1) res2.push_back(res[i]);
        report(res2);
        return ;
    }
    res[ans] = ')', res[ans - 1] = '(';
    vl re;
    rep(i, 0, n - 1) {
        if (i == ans || i == ans - 1) continue;
        re.push_back(i);
    }
    int m = sz(re);
    for (int i = 0; i < m - 1; i += 2) {
        vl tem;
        tem.push_back(ans), tem.push_back(ans);
        tem.push_back(re[i] + 1), tem.push_back(re[i + 1] + 1);
        tem.push_back(re[i] + 1);
        ll op = ask(sz(tem), tem);
        if (op == 0) {
            res[re[i]] = '(', res[re[i + 1]] = '(';
        } else if (op == 1) {
            res[re[i]] = '(', res[re[i + 1]] = ')';
        } else if (op == 2) {
            res[re[i]] = ')', res[re[i + 1]] = ')';
        } else {
            res[re[i]] = ')', res[re[i + 1]] = '(';
        }
    }
    if (m % 2 == 1) {
        vl tem;
        tem.push_back(ans);
        tem.push_back(re[m - 1] + 1);
        ll op = ask(sz(tem), tem);
        if (op == 1)
            res[re[m - 1]] = ')';
        else
            res[re[m - 1]] = '(';
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