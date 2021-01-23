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
    ll n,k;cin>>n>>k;
    ll ans = 0;
    if (k<0) k*=(-1);
    vector<ll> num(2*n+10);
    rep(i,2,2*n+1){
        num[i] = min((ll)i-1,2*n+1-i);
    }
    rep(i,k,2*n+1){
        ans += num[i]*num[i-k];
    }
    cout<<ans<<endl;
}