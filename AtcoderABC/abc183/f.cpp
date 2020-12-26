//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define INF 100000000
#define rep(i, s, n) for (int i = (int)(s); i < (int)(n); i++)
#define repp(i, n, s) for (int i = (int)(n); i >= (int)(s); i--)
#define mp make_pair
ll mod = 1000000007;
ll mod2 = 998244353;

struct UnionFind
{
    vector<int> par,siz;

    UnionFind(int n) : par(n), siz(n,1){
        for(int i=0;i<n;i++) par[i] = i;
    }

    int root(int x){
        if (par[x]==x) return x;
        return par[x] = root(par[x]);
    }

    int unite(int x,int y){
        int rx = root(x);
        int ry = root(y);
        if (rx==ry) return -1;
        if (siz[rx]<siz[ry]) swap(rx,ry);
        siz[rx] += siz[ry];
        par[ry] = rx;
        return rx;
    }

    bool same(int x,int y){
        int rx = root(x);
        int ry = root(y);
        return rx==ry;
    }

    int size(int x){
        return siz[root(x)];
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,q;cin>>n>>q;
    vector<map<int,int>> cls_num(n);
    rep(i,0,n){
        int c;cin>>c;
        cls_num[i][c]=1;
    }
    UnionFind uf(n);
    rep(i,0,q){
        int f;cin>>f;
        if(f==1){
            int a,b;cin>>a>>b;
            a--;b--;
            if (uf.size(a)<uf.size(b)) swap(a,b);
            int ra = uf.root(a);
            int rb = uf.root(b);
            if (ra==rb) continue;
            int rn = uf.unite(a,b);
            if (rn != ra){
                rb = ra;
                ra = rn;
            }
            for (auto pa:cls_num[rb]) cls_num[ra][pa.first] += pa.second;
            
        }else{
            int x,y;cin>>x>>y;
            x--;
            int rx = uf.root(x);
            cout<<cls_num[rx][y]<<endl;
        }
    }
}