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

ll modpow(ll a, ll b, ll mod) {
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
    ll n,m;cin>>n>>m;
    ll r = modpow(10,n,m);
    ll ans = 0;
    rep(i,0,m){
        ll x_1 = r + m*i;
        ll x_2 = m*m;
        ll mo = x_1 % x_2;
        if (modpow(10,n,x_2)==mo){
            ans = i;
            break;
        }
    }
    cout<<ans<<endl;
}