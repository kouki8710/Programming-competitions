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
    int n,m;cin>>n>>m;
    vector<ll> a(m),b(m-1);
    rep(i,0,m) cin>>a[i];
    if (m-n<=0){
        cout<<0<<endl;
        return 0;
    }
    sort(a.begin(),a.end());
    rep(i,0,m-1){
        b[i] = a[i+1]-a[i];
    }
    sort(b.begin(),b.end());
    ll ans = 0;
    rep(i,0,m-n){
        ans += b[i];
    }
    cout<<ans<<endl;
}