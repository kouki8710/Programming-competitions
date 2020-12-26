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
    ll ans = INF;
    string s;cin>>s;
    vector<ll> R(n+1),W(n+1);
    
    rep(i,0,n){
        if (s[i]=='R'){
            R[i]++;
        }else{
            W[i+1]++;
        }
    }

    rep(i,0,n){
        W[i+1] += W[i];
    }

    repp(i,n,1){
        R[i-1] += R[i];
    }

    rep(i,0,n+1){
        ans = min(ans, max(R[i],W[i]));
    }

    cout<<ans<<endl;
}