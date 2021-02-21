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
    ll n,m,k;cin>>n>>m>>k;
    vector<ll> a(n+1);
    ll ans = 0;
    rep(i,0,n) cin>>a[i];
    ll i1 = 0, ma=a[0],mi=a[0];
    ll bc = k;
    rep(i,1,n+1){
        
        ll ma2=ma, mi2=mi;
        if (i==n){
            ans += k+(i-i1)*(ma2-mi2);
            break;
        }
        ma = max(ma, a[i]);
        mi = min(mi, a[i]);
        
        if (k>(i-i1+1)*(ma-mi)-bc && (i-i1+1)<=m){
            bc = k + (i-i1+1)*(ma-mi);
        }else{
            ans += k+(i-i1)*(ma2-mi2);
            i1 = i;
            ma = a[i];
            mi = a[i];
            bc = k;
        }
    }
    cout<<ans<<endl;
}