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
    ll x,y,z,k;cin>>x>>y>>z>>k;
    vector<ll> a(x),b(y),c(z),d,e;
    rep(i,0,x) cin>>a[i];
    rep(i,0,y) cin>>b[i];
    rep(i,0,z) cin>>c[i];

    rep(i,0,y){
        rep(j,0,z){
            d.push_back(b[i]+c[j]);
        }
    }

    sort(d.begin(), d.end(), greater<ll>());
    // d.erase(unique(d.begin(), d.end()), d.end());

    rep(i,0,x){
        rep(j,0,min(k,(ll)d.size())){
            e.push_back(a[i]+d[j]);
        }
    }
    
    sort(e.begin(), e.end(), greater<ll>());

    // e.erase(unique(e.begin(),e.end()), e.end());

    rep(i,0,k){
        cout<<e[i]<<endl;
    }
}