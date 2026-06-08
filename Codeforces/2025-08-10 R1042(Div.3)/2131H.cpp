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
using i128 = __int128_t;
constexpr int MX = 1e6 + 5;
vector<int> divisors[MX];
vector<int> fac[MX];
auto init = [] {
    rep(i, 1, MX - 1) {
        for (int j = i; j < MX; j += i) {
            divisors[j].push_back(i);
        }
    }
    rep(i, 2, MX - 1) {
        if (fac[i].empty()) {
            for (int j = i; j < MX; j += i) {
                fac[j].push_back(i);
            }
        }
    }
    return 0;
}();
void solve() {
    ll n, m;
    cin >> n >> m;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    ll maxx = *max_element(all(a));
    vl cnt(maxx + 1);
    vl cnt2(maxx + 1);
    rep(i, 0, n - 1) {
        for (auto& p : divisors[a[i]]) {
            cnt[p]++;
        }
    }
    rep(i, 1, maxx) {
        if (!cnt[i]) continue;
        int tem = sz(fac[i]);
        ll tot = 0;
        rep(j, 1, (1 << tem) - 1) {
            ll tem2 = 1;
            rep(v, 0, tem - 1) {
                if (j >> v & 1) {
                    tem2 *= fac[i][v];
                }
            }
            if (popcount((unsigned)j) % 2 == 1)
                tot += cnt[tem2];
            else
                tot -= cnt[tem2];
        }
        cnt2[i] = tot;
    }
    vl deg(n);
    rep(i, 0, n - 1) { deg[i] = n - cnt2[a[i]] - (a[i] == 1); }
    int idx1 = -1, idx2 = -1;
    rep(i, 0, n - 1) {
        if (!deg[i]) continue;
        rep(j, 0, n - 1) {
            if (i == j) continue;
            if (__gcd(a[i], a[j]) == 1) {
                idx1 = i, idx2 = j;
                break;
            }
        }
        if (idx1 != -1) break;
    }
    if (idx1 == -1) {
        cout << 0 << endl;
        return;
    }
    rep(i, 0, n - 1) {
        if (i == idx1 || i == idx2) continue;
        ll tem = deg[i];
        if (__gcd(a[i], a[idx1]) == 1) tem--;
        if (__gcd(a[i], a[idx2]) == 1) tem--;
        if (tem == 0) continue;
        rep(j, 0, n - 1) {
            if (j == i || j == idx1 || j == idx2) continue;
            if (__gcd(a[i], a[j]) == 1) {
                cout << i + 1 << ' ' << j + 1 << ' ' << idx1 + 1 << ' ' << idx2 + 1 << endl;
                return;
            }
        }
    }
    vl idx3, idx4;
    rep(i, 0, n - 1) {
        if (i == idx1 || i == idx2) continue;
        if (__gcd(a[i], a[idx1]) == 1 && sz(idx3) < 2) idx3.push_back(i);
        if (__gcd(a[i], a[idx2]) == 1 && sz(idx4) < 2) idx4.push_back(i);
    }
    for (auto& p : idx3) {
        for (auto& q : idx4) {
            if (p != q) {
                cout << p + 1 << ' ' << idx1 + 1 << ' ' << q + 1 << ' ' << idx2 + 1 << endl;
                return;
            }
        }
    }
    cout << 0 << endl;
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
