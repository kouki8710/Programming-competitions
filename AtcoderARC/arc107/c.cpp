//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define INF 100000000
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

struct UnionFind {
    int _n;
    vector<int> par, siz;

    UnionFind(int n) : par(n), siz(n, 1) {
        _n = n;
        for (int i = 0; i < n; i++) par[i] = i;
    }

    int root(int x) {
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    int unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return -1;
        if (siz[rx] < siz[ry]) swap(rx, ry);
        // rx>=ry rxが親
        siz[rx] += siz[ry];
        par[ry] = rx;  //rxにryを結合
        return rx;
    }

    bool same(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }

    int size(int x) {
        return siz[root(x)];
    }
};

ll fraction (ll n){
    if (n==1) return 1;
    return n * fraction(n-1) % mod2;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,k;cin>>n>>k;
    vector<vector<ll>> a(n,vector<ll>(n));
    rep(i,0,n){
        rep(j,0,n){
            cin>>a[i][j];
        }
    }

    UnionFind uf1(n);
    ll ans = 1;

    rep(i,0,n){
        rep(j,0,n){
            ll f = 0;
            if (i<j){
                f = 1;
                rep(s,0,n){
                    if (a[i][s]+a[j][s]>k){
                        f = 0;
                    }
                }
            }
            if (f) {
                uf1.unite(i,j);
            }
        }
        
    }

    rep(i,0,n){
        if (uf1.par[i]==i){
            ans = ans * fraction(uf1.size(i)) %mod2;
        }
    }

    UnionFind uf2(n);

    rep(i,0,n){
        rep(j,0,n){
            ll f = 0;
            if (i<j){
                f = 1;
                rep(s,0,n){
                    if (a[s][i]+a[s][j]>k){
                        f = 0;
                    }
                }
            }
            if (f) {
                uf2.unite(i,j);
            }
        }
    }
    
    rep(i,0,n){
        if (uf2.par[i]==i){
            ans = ans * fraction(uf2.size(i)) %mod2;
        }
    }

    cout<<ans<<endl;
}