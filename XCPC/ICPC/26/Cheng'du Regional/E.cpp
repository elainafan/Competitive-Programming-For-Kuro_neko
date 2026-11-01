#include <bits/stdc++.h>
#define ll long long
#define rep(i, x, y) for (ll i = x; i <= y; i++)
#define frep(i, x, y) for (ll i = x; i >= y; i--)
#define all(x) (x).begin(), (x).end()
#define all2(x) (x).rbegin(), (x).rend()
#define sz(a) (int)a.size()
#define pll pair<ll, ll>
#define trl tuple<ll, ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vvl vector<vector<ll>>
using namespace std;
using i128 = __int128_t;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// 用法说明：
// Point 同时表示点和向量，b-a 表示从 a 指向 b 的向量。
// dot(a,b) 是点积；cross(a,b) 是叉积。
// cross(o,a,b) 的符号判断转向：>0 左转，=0 共线，<0 右转。
// norm2(v) 是长度平方，length(v) 是向量长度，dist(a,b) 是两点距离。
// perp(v) 将向量逆时针转 90°；rotate(v,rad) 按弧度旋转。
// same(a,b) 使用 EPS 判等；operator== 是精确判等，只用于排序去重。

// 整数坐标版本：坐标和基础运算均使用 i128，适合需要精确判断的场景。
// 需要开方的结果返回 ld；i128 来自 1.cpp。
struct PointI {
    i128 x = 0, y = 0;

    auto operator+(const PointI& p) const -> PointI { return {x + p.x, y + p.y}; }

    auto operator-(const PointI& p) const -> PointI { return {x - p.x, y - p.y}; }

    auto operator*(i128 k) const -> PointI { return {x * k, y * k}; }

    auto operator<(const PointI& p) const -> bool { return x != p.x ? x < p.x : y < p.y; }

    auto operator==(const PointI& p) const -> bool { return x == p.x && y == p.y; }
};

auto cross(const PointI& a, const PointI& b) -> i128 { return a.x * b.y - a.y * b.x; }

auto cross(const PointI& o, const PointI& a, const PointI& b) -> i128 { return cross(a - o, b - o); }

auto convexHull(vector<PointI>& p) -> vi {
    int n = sz(p);
    vi ord(n);
    rep(i, 0, n - 1) ord[i] = i;
    sort(all(ord), [&](const int& x, const int& y) { return p[x] < p[y]; });
    ord.erase(unique(all(ord), [&](const int& x, const int& y) { return p[x] == p[y]; }), ord.end());
    if (sz(ord) <= 1) return ord;
    int m = sz(ord);
    vi h(2 * m);
    int k = 0;
    for (auto& x : ord) {
        while (k >= 2 && cross(p[h[k - 2]], p[h[k - 1]], p[x]) <= 0) k--;
        h[k++] = x;
    }
    for (int i = sz(ord) - 2, t = k + 1; i >= 0; i--) {
        while (k >= t && cross(p[h[k - 2]], p[h[k - 1]], p[ord[i]]) <= 0) k--;
        h[k++] = ord[i];
    }
    h.resize(k - 1);
    return h;
};

int InConvex(const vector<PointI>& h, const PointI& p) {
    int n = sz(h);
    if (n < 3 || cross(h[0], h[1], p) <= 0 || cross(h[0], h[n - 1], p) >= 0) return -1;
    int l = 1, r = n - 2, ans = 0, mid;
    auto check = [&](int mid) -> bool { return cross(h[0], h[mid], p) >= 0; };
    while (l <= r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else
            r = mid - 1;
    }
    if (cross(h[ans], h[ans + 1], p) <= 0) return -1;
    return ans;
};

bool inTriangle(const PointI& a, const PointI& b, const PointI& c, const PointI& d) {
    i128 x = cross(a, b, d), y = cross(b, c, d), z = cross(c, a, d);
    return (x < 0 && y < 0 && z < 0) || (x > 0 && y > 0 && z > 0);
};

void solve() {
    ll n, q, x, y;
    cin >> n >> q;
    vector<PointI> p;
    rep(i, 0, n - 1) {
        cin >> x >> y;
        p.emplace_back(x, y);
    }
    vi id = convexHull(p);
    int m = sz(id);
    vector<PointI> h;
    rep(i, 0, m - 1) h.push_back(p[id[i]]);
    int idx = -1;
    if (m == 4) {
        rep(i, 0, n - 1) {
            if (cross(h[0], h[2], p[i]) != 0 && cross(h[1], h[3], p[i]) != 0) {
                idx = i;
                break;
            }
        }
    }
    rep(_, 0, q - 1) {
        cin >> x >> y;
        PointI tem(x, y);
        int l = InConvex(h, tem);
        if (l == -1) {
            cout << -1 << endl;
            continue;
        }
        if (cross(h[0], h[l], tem) > 0) {
            cout << 3 << endl;
            cout << id[0] + 1 << ' ' << id[l] + 1 << ' ' << id[l + 1] + 1 << endl;
            continue;
        }
        vi cand = {id[0], id[l - 1], id[l], id[l + 1]};
        if (m >= 5)
            cand.push_back(id[(l == 2 ? 4 : 1)]);
        else if (m == 4 && idx != -1)
            cand.push_back(idx);
        bool flag = false;
        int m1 = sz(cand);
        for (int i = 0; i <= m1 - 1 && !flag; i++) {
            for (int j = i + 1; j <= m1 - 1 && !flag; j++) {
                for (int v = j + 1; v <= m1 - 1 && !flag; v++) {
                    if (inTriangle(p[cand[i]], p[cand[j]], p[cand[v]], tem)) {
                        cout << 3 << endl;
                        cout << cand[i] + 1 << ' ' << cand[j] + 1 << ' ' << cand[v] + 1 << endl;
                        flag = true;
                        break;
                    }
                }
            }
        }
        if (!flag) {
            cout << 4 << endl;
            rep(i, 0, 3) cout << cand[i] + 1 << ' ';
            cout << endl;
            continue;
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
