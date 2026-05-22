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
void solve() {
    string s;
    cin >> s;
    if (sz(s) == 1) {
        cout << s << endl;
        return;
    }
    vi cnt(10);
    rep(i, 0, sz(s) - 1) { cnt[s[i] - '0']++; }
    int ans = 0;
    rep(i, 0, 9) ans += cnt[i] * i;
    int maxx = 0;
    rep(i, 1, ans) {
        int sum = i;
        int tem = i;
        vi temp;
        temp.push_back(i);
        while (tem > 0) {
            if (0 <= tem && tem <= 9) {
                sum += tem;
                temp.push_back(i);
                break;
            }
            int tem2 = 0;
            int tem3 = tem;
            while (tem3 > 0) {
                tem2 += tem3 % 10;
                tem3 /= 10;
            }
            sum += tem2;
            temp.push_back(tem2);
            tem = tem2;
        }
        if (1 <= i && i <= 9) {
            if (sum != ans || !cnt[i]) continue;
        } else {
            if (sum != ans) continue;
        }
        int sum2 = i;
        vi cnt2(10);
        while (sum2 >= 10) {
            int tem2 = sum2;
            int tem3 = 0;
            while (tem2 > 0) {
                tem3 += tem2 % 10;
                cnt2[tem2 % 10]++;
                tem2 /= 10;
            }
            sum2 = tem3;
        }
        cnt2[sum2]++;
        int sum3 = 0;
        bool flag = true;
        frep(i, 9, 0) {
            if (cnt2[i] > cnt[i]) {
                flag = false;
                break;
            }
            sum3 += i * (cnt[i] - cnt2[i]);
        }
        if (sum3 != i || !flag) continue;
        maxx = i;
        break;
    }
    string res = "";
    int maxx2 = maxx;
    vi cnt2(10);
    while (maxx2 >= 10) {
        int tem2 = maxx2;
        int tem3 = 0;
        while (tem2 > 0) {
            tem3 += tem2 % 10;
            cnt2[tem2 % 10]++;
            tem2 /= 10;
        }
        maxx2 = tem3;
    }
    cnt2[maxx2]++;
    frep(i, 9, 0) { rep(j, 0, cnt[i] - cnt2[i] - 1) res.push_back('0' + i); }
    vector<string> tem2;
    tem2.push_back(res);
    while (maxx >= 10) {
        tem2.push_back(to_string(maxx));
        int tem = 0;
        while (maxx > 0) {
            tem += maxx % 10;
            maxx /= 10;
        }
        maxx = tem;
    }
    tem2.push_back(to_string(maxx));
    int tot = 0;
    for (auto& p : tem2) {
        rep(i, 0, sz(p) - 1) { tot += (p[i] == '0'); }
    }
    rep(i, 0, cnt[0] - tot - 1) res.push_back('0');
    rep(i, 1, sz(tem2) - 1) res += tem2[i];
    cout << res << endl;
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
