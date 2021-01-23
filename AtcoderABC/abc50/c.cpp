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

ll modpow(ll a, ll b) {
    ll r = 1;
    while (b) {
        r = r * ((b % 2) ? a : 1) % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return r;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;cin>>n;
    vector<ll> a(n);
    rep(i,0,n) cin>>a[i];
    map<ll,ll> b;
    rep(i,0,n) b[a[i]]++;
    ll ans = 0;
    if (n%2==0){
        int f = 0;
        rep(i,0,n){
            if (i%2==1){
                if (b[i]!=2){
                    f = 1;
                    break;
                }
            }
        }
        if (f==0){
            ans = modpow(2,n/2);
        }
    }else{
        int f = 0;
        rep(i,1,n){
            if (i%2==0 && b[i]!=2){
                f = 1;
                break;
            }
        }
        if (b[0]!=1){
            f = 1;
        }
        if (f==0){
            ans = modpow(2,n/2);
        }
    }
    cout<<ans<<endl;
}