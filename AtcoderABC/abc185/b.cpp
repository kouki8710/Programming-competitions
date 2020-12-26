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
    ll n,m,t;cin>>n>>m>>t;
    ll ans = n;
    ll f = 0;
    ll time = 0;
    rep(i,0,m){
        ll a,b;cin>>a>>b;
        ans -= a-time;
        if (ans<=0){
            f = 1;
            break;
        }
        ans = min(n, ans+b-a);
        time = b;
    }
    
    ans -= t - time;
    if (ans<=0){
        f = 1;
    }

    if (f){
        cout<<"No"<<endl;
    }else{
        cout<<"Yes"<<endl;
    }
}