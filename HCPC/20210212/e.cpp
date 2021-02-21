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

ll fact(ll num){
    if (num==0) return 0;
    if (num==1) return 1;
    return fact(num-1)*num%mod;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll r,c;cin>>r>>c;
    ll n;cin>>n;
    vector<ll> x(n),y(n), seenx(r),seeny(c);
    rep(i,0,n){
        cin>>x[i]>>y[i];
        x[i]--;y[i]--;
        seenx[x[i]] = 1;
        seeny[y[i]] = 1;
    }
    ll ans = 1;

    ll x1 = 0,x2 =0, y1=0, y2=0;
    rep(i,0,r){
        if (seenx[i]==1){
            x1 = i;
            break;
        }
    }

    rep(i,0,c){
        if (seeny[i]==1){
            y1 = i;
            break;
        }
    }

    repp(i,r-1,0){
        if (seenx[i]==1){
            x2 = i+1;
            break;
        }
    }

    repp(i,c-1,0){
        if (seeny[i]==1){
            y2 = i+1;
            break;
        }
    }
    cout<<x1<<x2<<" "<<y1<<y2<<endl;

    ans = fact((x2-x1)*(y2-y1) - n)%mod;

    ll b2 = r-x2, u2 = x1, r2 = r-y2;
    cout<<ans<<endl;
}