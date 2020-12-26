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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll a,b,c;cin>>a>>b>>c;
    ll ans = 0;
    ll x = a*(a+1)/2%mod2;
    ll y = b*(b+1)/2%mod2;
    ll z = c*(c+1)/2%mod2;
    ans = x*y%mod2*z%mod2;
    cout<<ans%mod2<<endl;
}