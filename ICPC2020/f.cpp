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

void solve(ll n, ll m){

    map<ll,vector<PL>> G;
    ll max_s = 0;
    rep(i,0,m){
        ll a,b,c;cin>>a>>b>>c;
        a--;b--;
        max_s = max(max_s, c);
        G[c].push_back(mp(a,b));
    }

    ll cnt = -1;
    vector<ll> ans;
    UnionFind uf(n);
    ll num_s = max_s;
    repp(i,max_s,1){

        for (PL ne : G[i]){
            uf.unite(ne.first, ne.second);
            if (!ans.size() || !uf.same(ans[0],ne.first)){
                if (uf.size(ne.first) > cnt){
                    cnt = uf.size(ne.first);
                    ans = {ne.first};
                    num_s = i;
                }
            }
        }
    }

    UnionFind uf2(n);
    repp(i,max_s,num_s){
        for (PL ne : G[i]){
            uf2.unite(ne.first, ne.second);
        }
    }

    ll max_size = 0;
    rep(i,0,n){
        max_size = max(max_size, (ll)uf2.size(i));
    }
    vector<ll> ans2;
    rep(i,0,n){
        if (max_size == uf2.size(i)){
            ans2.push_back(i);
        }
    }
    rep(i,0,ans2.size()){
        cout<<ans2[i]+1<<" ";
    }
    cout<<endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while (1){
        ll n,m;cin>>n>>m;
        if (n==0 && m==0) break;
        solve(n,m);
    }
    
}