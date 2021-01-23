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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll h,w,k;cin>>h>>w>>k;
    vector<vector<char>> G(h,vector<char>(w));
    vector<vector<ll>> dp(h,vector<ll>(w));
    rep(i,0,k){
        int a,b;char c;
        cin>>a>>b>>c;
        a--;b--;
        G[a][b] = c;
    }
    ll inv_3 = modpow(3,mod-2);
    dp[0][0] = modpow(3,h*w-k);
    rep(i,0,h){
        rep(j,0,w){
            ll r1 = 0;
            ll b1 = 0;
            if (G[i][j]=='X'){
                r1 = dp[i][j];
                b1 = dp[i][j];
            }else if(G[i][j]=='R'){
                r1 = dp[i][j];
            }else if(G[i][j]=='D'){
                b1 = dp[i][j];
            }else{
                r1 = dp[i][j] * 2 %mod * inv_3 % mod;
                b1 = dp[i][j] * 2 %mod * inv_3 % mod;
            }
            if (j+1<w){
                dp[i][j+1] = (dp[i][j+1]+r1)%mod;
            }
            if (i+1<h){
                dp[i+1][j] = (dp[i+1][j]+b1)%mod;
            }
        }
    }
    cout<<dp[h-1][w-1]<<endl;
}