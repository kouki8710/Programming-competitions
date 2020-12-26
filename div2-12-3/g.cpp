//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define INF 100000000
#define rep(i, s, n) for (int i = (int)(s); i < (int)(n); i++)
#define repp(i, n, s) for (int i = (int)(n); i >= (int)(s); i--)
#define mp make_pair
#define tp make_tuple
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
typedef tuple<int,int,int> T;
typedef tuple<ll,ll,ll> TL;
ll mod = 1000000007;
ll mod2 = 998244353;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,k;cin>>n>>k;
    vector<ll> a(n);
    rep(i,0,n) cin>>a[i];
    vector<vector<ll>> dp(n+1,vector<ll>(k+1)), b(n+1, vector<ll>(k+2));
    dp[0][0] = 1;
    rep(i,0,n){
        rep(j,0,k+1){
            b[i][j+1] = (b[i][j] + dp[i][j])%mod;
        }
        rep (j,0,k+1){
            dp[i+1][j] = (dp[i+1][j] + b[i][j+1] - b[i][max(j-a[i],(ll)0)])%mod;
        }
    }
    cout<<(dp[n][k]+mod)%mod<<endl;
}