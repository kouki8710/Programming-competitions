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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll h,w,m;cin>>h>>w>>m;
    vector<ll> tate(h+1,-1), yoko(w+1,-1);
    rep(i,0,m){
        ll x,y;cin>>x>>y;
        tate[x] = min(tate[x],y);
        yoko[y] = min(yoko[y], x);
    }

    ll ans = 0;
    rep(i,1,m+1){
        if (tate[i]==-1){
            continue;
        }

        int x = i;
        int y = tate[i];
        
    }
}