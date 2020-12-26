//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define INF 100000000
#define INFL 
#define rep(i, s, n) for (ll i = (ll)(s); i < (ll)(n); i++)
#define repp(i, n, s) for (ll i = (ll)(n); i >= (ll)(s); i--)
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
    ll n;cin>>n;
    ll num = 0;
    ll ans = n + 1;
    if (n==1){
        cout<<1<<endl;
        return 0;
    }else if(n==2){
        cout<<1<<endl;
        return 0;
    }
    rep(i,1,n+1){
        num += i;
        if (num>n+1){
            ans -= i-1;
            break;
        }
    }
    cout<<ans<<endl;
}