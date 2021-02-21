//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define INF 1000000000
#define INFL 1000000000000000000
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

// i=0から
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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;cin>>n;
    int m;cin>>m;
    UnionFind uf(n);
    rep(i,0,m){
        ll a,b;cin>>a>>b;
        a--;b--;
        uf.unite(a,b);
    }
    ll ans = 0;
    rep(i,0,n){
        if (uf.par[i]==i) ans++;
    }
    cout<<ans-1<<endl;
}