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
ll mod = 998244353;

ll modpow(ll a, ll b) {
    ll r = 1;
    while (b) {
        r = r * ((b % 2) ? a : 1) % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return r;
}

ll comb(ll N_, ll C_) {
    const int NUM_ = 400001;
    static ll fact[NUM_ + 1], factr[NUM_ + 1], inv[NUM_ + 1];
    if (fact[0] == 0) {
        inv[1] = fact[0] = factr[0] = 1;
        for (int i = 2; i <= NUM_; ++i) inv[i] = inv[mod % i] * (mod - mod / i) % mod;
        for (int i = 1; i <= NUM_; ++i) fact[i] = fact[i - 1] * i % mod, factr[i] = factr[i - 1] * inv[i] % mod;
    }
    if (C_ < 0 || C_ > N_) return 0;
    return factr[C_] * fact[N_] % mod * factr[N_ - C_] % mod;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,m,k;cin>>n>>m>>k;
    if (n==1 || m==1){
        if (n==1 && m==1){
            cout<<k<<endl;
        }else if(n==1){
            cout<<modpow(k,m)<<endl;
        }else if(m==1){
            cout<<modpow(k,n)<<endl;
        }
        return 0;
    }

    ll ans = 0;
    rep(i,1,k+1){
        ll num = (modpow(i,n)-modpow(i-1,n)+mod)%mod;
        ll num2 = modpow(k-i+1,m);
        num = (num*num2)%mod;
        ans = (ans+num)%mod;
    }
    cout<<ans%mod<<endl;
}