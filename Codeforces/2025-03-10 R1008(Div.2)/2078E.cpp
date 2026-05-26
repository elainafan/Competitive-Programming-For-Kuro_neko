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
const int tem1 = 715827882;
const int tem2 = 357913941;
ll ask(ll l) {
    cout << l << '\n';
    cout.flush();
    ll op;
    cin >> op;
    return op;
}
ll report() {
    cout << "! " << '\n';
    cout.flush();
    ll op;
    cin >> op;
    return op;
}
void report2(ll x) {
    cout << x << '\n';
    cout.flush();
}
void solve() {
    ll tem3 = ask(tem1);
    tem3 -= 2 * tem1;
    ll tem4 = ask(tem2);
    tem4 -= 2 * tem2;
    ll m = report();
    ll x = 0, y = 0;
    for (int i = 0; i < 30; i += 2) {
        if ((tem3 >> i) & 1)
            x |= (1LL << i);
        else if ((tem3 >> (i + 1)) & 1)
            x |= (1LL << i), y |= (1LL << i);
    }
    for (int i = 1; i < 30; i += 2) {
        if ((tem4 >> i) & 1)
            x |= (1LL << i);
        else if ((tem4 >> (i + 1)) & 1)
            x |= (1LL << i), y |= (1LL << i);
    }
    report2((x | m) + (y | m));
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