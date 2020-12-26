//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define INF 100000000
#define rep(i, s, n) for (ll i = (int)(s); i < (int)(n); i++)
#define repp(i, n, s) for (int i = (int)(n); i >= (int)(s); i--)
#define mp make_pair
ll mod = 1000000007;
ll mod2 = 998244353;

ll calc_xor(ll a){
    ll num = 0;
    rep(i,1,64){
        ll k = pow(2,i);
        ll k2 = pow(2,i-1);
        ll s = (a+1)/k*k2 + max((a+1)%k-k2,0LL);
        s %= 2;
        num += s*k2;
    }
    return num;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll a,b;cin>>a>>b;
    a--;
    ll s1 = calc_xor(a);
    ll s2 = calc_xor(b);
    cout<< (s1^s2) <<endl;
}