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
    vl a(n), b(n);
    rep(i, 0, n - 1) cin >> a[i];
    rep(i, 0, n - 1) cin >> b[i];
    vector<bitset<32>> ma(n);
    vector<bitset<32>> ma2(n);
    rep(i, 0, n - 1) ma[i] = bitset<32>(a[i]);
    rep(i, 0, n - 1) ma2[i] = bitset<32>(b[i]);
    frep(i, 31, 0) {
        int cnt0 = 0, cnt1 = 0;
        rep(j, 0, n - 1) {
            if (j % 2 == 0 && ma[j][i] != ma2[j][i]) cnt0++;
            if (j % 2 == 1 && ma[j][i] != ma2[j][i]) cnt1++;
        }
        if (cnt0 == 0 && cnt1 == 0)
            continue;
        else if (cnt0 == 0) {
            if (cnt1 % 2 == 1) {
                cout << "Mai" << endl;
                return;
            }
        } else if (cnt1 == 0) {
            if (cnt0 % 2 == 1) {
                cout << "Ajisai" << endl;
                return;
            }
        } else {
            if ((cnt0 + cnt1) % 2 == 0) continue;
            int las = -1, las2 = -1;
            for (int j = 0; j <= n - 1; j += 2) {
                if (ma[j][i] != ma2[j][i]) las = j;
            }
            for (int j = 1; j <= n - 1; j += 2) {
                if (ma[j][i] != ma2[j][i]) las2 = j;
            }
            if (las < las2)
                cout << "Mai" << endl;
            else
                cout << "Ajisai" << endl;
            return;
        }
    }
    cout << "Tie" << endl;
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
