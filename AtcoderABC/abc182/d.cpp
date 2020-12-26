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
    int n;cin>>n;
    vector<ll> a(n),b(n+1),c(n+1);
    rep(i,0,n) cin>>a[i];
    rep(i,0,n){
        b[i+1] = b[i] + a[i];
        if (c[i]>=b[i+1]){
            c[i+1] = c[i];
        }else{
            c[i+1] = b[i+1]; 
        }
    }
    ll ans = 0,now = 0;
    rep(i,1,n+1){
        if (now+c[i]>ans){
            ans = now+c[i];
        }
        now += b[i];
    }
    cout<<ans<<endl;
}
