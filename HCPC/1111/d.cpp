//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define INF 100000000
#define rep(i, s, n) for (int i = (int)(s); i < (int)(n); i++)
#define repp(i, n, s) for (int i = (int)(n); i >= (int)(s); i--)
#define mp make_pair
ll mod = 1000000007;
ll mod2 = 998244353;

ll modpow(ll a, ll b, ll mod_in) {
    ll r = 1;
    while (b) {
        r = r * ((b % 2) ? a : 1) % mod_in;
        a = a * a % mod_in;
        b >>= 1;
    }
    return r;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;cin>>n;
    rep(i,1,n){
        ll num = i;
        rep(j,0,5){
            num = modpow(num,n,n);
            cout<<num<<" ";
        }
        cout<<endl;
    }
}

