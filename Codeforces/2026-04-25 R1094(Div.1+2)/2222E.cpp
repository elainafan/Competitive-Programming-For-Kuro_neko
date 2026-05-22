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
void init(ll a) {
    cout << a << '\n';
    cout.flush();
    return;
}
ll insert(ll l) {
    cout << "I " << l << '\n';
    cout.flush();
    ll op;
    cin >> op;
    return op;
}
ll query(ll l) {
    cout << "Q " << l << '\n';
    cout.flush();
    ll op;
    cin >> op;
    return op;
}
void report(ll a, ll b) {
    cout << "A " << a << ' ' << b << '\n';
    cout.flush();
}
void solve() {
    int n;
    cin >> n;
    ll k = 0, c = 0;
    init((1LL << n) - 1);
    int tem = insert(0);
    if (tem == 1) {
        c = (1LL << n) - 1;
        int tem2 = insert((1LL << n) - 1);
        if (tem2 == 1)
            k = 2;
        else
            k = 3;
        report(k, c);
        return;
    } else {
        int tem2 = query(1);
        if (tem2 == 1) {
            k = 1;
            if (n == 1)
                c = 1;
            else {
                int tem3 = tem;
                rep(i, 0, n - 1) {
                    int tem4 = insert(1LL << i);
                    if (tem4 == tem3 + 1) c += (1LL << i);
                    tem3 = tem4;
                }
            }
            report(k, c);
            return;
        } else {
            ll l = 1, r = (1LL << n) - 2;
            while (l < r) {
                ll mid = (l + r + 1) / 2;
                ll tem3 = query(mid);
                if (tem3 == 2)
                    l = mid;
                else
                    r = mid - 1;
            }
            ll tem3 = insert(l);
            if (tem3 == 2)
                k = 2;
            else
                k = 3;
            report(k, l);
            return;
        }
    }
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
