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
    ll n;
    cin >> n;
    vl even;
    vl odd;
    vl tem;
    rep(i, 1, n) {
        if (i % 2 == 0)
            even.push_back(i);
        else if (i % 3 == 0)
            odd.push_back(i);
        else
            tem.push_back(i);
    }
    while (!tem.empty() && sz(even) >= 2) {
        cout << tem.back() << ' ';
        tem.pop_back();
        cout << even.back() << ' ';
        even.pop_back();
        cout << even.back() << ' ';
        even.pop_back();
    }
    while (!tem.empty() && sz(odd) >= 2) {
        cout << tem.back() << ' ';
        tem.pop_back();
        cout << odd.back() << ' ';
        odd.pop_back();
        cout << odd.back() << ' ';
        odd.pop_back();
    }
    while (!even.empty()) {
        cout << even.back() << ' ';
        even.pop_back();
    }
    while (!odd.empty()) {
        cout << odd.back() << ' ';
        odd.pop_back();
    }
    while (!tem.empty()) {
        cout << tem.back() << ' ';
        tem.pop_back();
    }
    cout << endl;
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
