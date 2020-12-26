//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, s, n) for (int i = (int)(s); i < (int)(n); i++)
#define repp(i, n, s) for (int i = (int)(n); i >= (int)(s); i--)
#define mp make_pair
#define tp make_tuple
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
typedef tuple<int,int,int> T;
typedef tuple<ll,ll,ll> TL;
ll mod = 1000000007;
ll mod2 = 998244353;

template <typename X>
struct SegTree {

    using FX = function<X(X, X)>; // X•X -> X となる関数の型
    int n;
    FX fx; // 演算
    const X ex; // 単位元
    vector<X> dat;

    SegTree(int n_, FX fx_, X ex_) : n(), fx(fx_), ex(ex_), dat(n_ * 4, ex_) {
        int x = 1;
        while (n_ > x) {
            x *= 2;
        }
        n = x;
    }

    void set(int i, X x) { dat[i + n - 1] = x; }

    void build() {
        for (int k = n - 2; k >= 0; k--) dat[k] = fx(dat[2 * k + 1], dat[2 * k + 2]);
    }

    void update(int i, X x) {
        i += n - 1;
        dat[i] = x;
        while (i > 0) {
            i = (i - 1) / 2;  // parent
            dat[i] = fx(dat[i * 2 + 1], dat[i * 2 + 2]);
        }
    }

    X query(int a, int b) { return query_sub(a, b, 0, 0, n); }

    X query_sub(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) {
            return ex;
        } else if (a <= l && r <= b) {
            return dat[k];
        } else {
            X vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
            X vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            return fx(vl, vr);
        }
    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;cin>>n;
    string s;cin>>s;
    int q;cin>>q;
    auto fx = [](int x1, int x2) -> int {return x1 | x2;};
    int ex = 0;
    SegTree<int> seg(n, fx, ex);
    rep(i,0,n){
        seg.set(i, 1<<int(s[i]-'a') );
    }
    seg.build();
    rep(i,0,q){
        int num;cin>>num;
        if (num==1){
            int c;cin>>c;
            char c2; cin>>c2;
            c--;
            seg.update(c, 1<<int(c2-'a') );
        }else{
            int l,r;cin>>l>>r;
            int b = seg.query(l-1,r);
            int ans = 0;
            while (b>0){
                if (b & 1) ans++;
                b>>=1;
            }
            cout<<ans<<endl;
        }
    }
}