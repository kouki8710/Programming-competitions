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

template <typename T>
struct RUQ {
    const T INF = numeric_limits<T>::max();
    int n;
    vector<T> dat, lazy;
    RUQ(int n_) : n(), dat(n_ * 4, INF), lazy(n_ * 4, INF) {
        int x = 1;
        while (n_ > x) x *= 2;
        n = x;
    }
    /* lazy eval */
    void eval(int k) {
        if (lazy[k] == INF) return;  // 更新するものが無ければ終了
        if (k < n - 1) {             // 葉でなければ子に伝搬
            lazy[k * 2 + 1] = min(lazy[k * 2 + 1],lazy[k]);
            lazy[k * 2 + 2] = min(lazy[k * 2 + 2],lazy[k]);
        }
        // 自身を更新
        dat[k] = min(dat[k],lazy[k]);
        lazy[k] = INF;
    }

    void update(int a, int b, T x, int k, int l, int r) {
        eval(k);
        if (a <= l && r <= b) {  // 完全に内側の時
            lazy[k] = x;
            eval(k);
        } else if (a < r && l < b) {                     // 一部区間が被る時
            update(a, b, x, k * 2 + 1, l, (l + r) / 2);  // 左の子
            update(a, b, x, k * 2 + 2, (l + r) / 2, r);  // 右の子
            dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }

    void update(int a, int b, T x) { update(a, b, x, 0, 0, n); }

    T query_sub(int a, int b, int k, int l, int r) {
        eval(k);
        if (r <= a || b <= l) {  // 完全に外側の時
            return INF;
        } else if (a <= l && r <= b) {  // 完全に内側の時
            return dat[k];
        } else {  // 一部区間が被る時
            T vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
            T vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            return min(vl, vr);
        }
    }
    T query(int a, int b) { return query_sub(a, b, 0, 0, n); }
    /* debug */
    inline T operator[](int a) { return query(a, a + 1); }
    void print() {
        for (int i = 0; i < 2 * n - 1; ++i) {
            cout << (*this)[i];
            if (i != n) cout << ",";
        }
        cout << endl;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,q;cin>>n>>q;
    RUQ<int> ruq(q);
    vector<int> s(n),t(n),x(n),d(q);
    rep(i,0,n){
        cin>>s[i]>>t[i]>>x[i];
    }

    rep(i,0,q){
        cin>>d[i];
        // ruq.set(i,d[i]);
    }

    // ruq.build();
    rep(i,0,n){
        int l = lower_bound(d.begin(),d.end(),s[i] - x[i]) - d.begin();
        int r = lower_bound(d.begin(),d.end(),t[i] - x[i]) - d.begin();
        ruq.update(l,r,x[i]);
    }
    rep(i,0,q){
        int ans = ruq.query(i,i+1);
        if(ans==numeric_limits<int>::max()){
            cout<<-1<<endl;
        }else{
            cout<<ans<<endl;
        }
    }
}