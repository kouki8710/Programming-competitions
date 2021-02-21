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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ld x,y,r;cin>>x>>y>>r;
    x = abs(x);
    y = abs(y);
    x = x - (ll)x;
    y = y - (ll)y;
    ll ans = 0;
    cout<<sqrt(r*r)<<endl;
    rep(i,(ll)-r-1,(ll)r+1){
        if ( r*r-(i-x)*(i-x)>=0 ){
            ld k = sqrt(r*r-(i-x)*(i-x));
            ans += floor(abs(y-k)) + floor(y+k);
            if (y-k<=0) ans++; 
        }
    }
    cout<<ans<<endl;
}