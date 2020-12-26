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
    ll x,y,a,b;cin>>x>>y>>a>>b;
    ll ans = (y-x-1)/b;
    ll cnt = 0;
    while (x*a<y && a*x<=x+b){
        x*=a;
        ans = max (ans,(y-x-1)/b+cnt);
        cnt++;
    }
    cout<<ans<<endl;
}