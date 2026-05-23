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
// FFT求卷积，适合普通整数系数；如果需要取模且模数友好，优先用NTT。
// convolution_ll(a, b)返回c，其中c[k]=sum(a[i]*b[j])，i+j=k
using cd = complex<double>;
const double PI = acos(-1.0);

void fft(vector<cd>& a, bool inv) {
    int n = sz(a);
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (inv ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            rep(j, 0, len / 2 - 1) {
                cd u = a[i + j];
                cd v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }
    if (inv) {
        for (cd& x : a) x /= n;
    }
}

vl convolution_ll(vl a, vl b) {
    if (a.empty() || b.empty()) return {};
    int need = sz(a) + sz(b) - 1;
    int n = 1;
    while (n < need) n <<= 1;
    vector<cd> fa(all(a)), fb(all(b));
    fa.resize(n);
    fb.resize(n);
    fft(fa, false);
    fft(fb, false);
    rep(i, 0, n - 1) fa[i] *= fb[i];
    fft(fa, true);
    vl res(need);
    rep(i, 0, need - 1) res[i] = llround(fa[i].real());
    return res;
}
void solve() {
    int n, x, y, d;
    cin >> n >> d;
    d--;
    vvi ma(n);
    rep(i, 1, n - 1) {
        cin >> x >> y;
        ma[x - 1].push_back(y - 1);
        ma[y - 1].push_back(x - 1);
    }
    ll ans = 0;
    rep(i, 0, n - 1) {
        vl tem(d + 1), tem2(d + 1);
        for (int& p : ma[i]) {
            vl dep(d + 1);
            auto dfs = [&](this auto&& dfs, int x, int pa, int dd) -> void {
                if (dd > d) return;
                dep[dd]++;
                for (int& q : ma[x]) {
                    if (q == pa) continue;
                    dfs(q, x, dd + 1);
                }
                return;
            };
            dfs(p, i, 1);
            rep(j, 1, d - 1) {
                ans += dep[j] * tem[d - j];
                ans += dep[j] * tem2[d - j];
            }
            vl tem3 = convolution_ll(dep, tem);
            rep(j, 0, min(d, sz(tem3) - 1)) { tem2[j] += tem3[j]; }
            rep(j, 1, d) tem[j] += dep[j];
        }
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
