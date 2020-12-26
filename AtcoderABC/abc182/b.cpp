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
    vector<ll> a(n);
    rep(i,0,n){
        cin>>a[i];
    }
    ll ans = 0;
    ll gcd = 0;
    rep(i,2,1001){
        ll num = 0;
        rep(j,0,n){
            if (a[j]%i==0) num++;
        }
        if (gcd<num){
            gcd = num;
            ans = i;
        }
    }
    cout<<ans<<endl;
}
