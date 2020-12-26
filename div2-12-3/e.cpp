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
    int n,p;cin>>n>>p;
    vector<vector<ll>> dp(n+1,vector<ll>(2));
    vector<ll> a(n);
    rep(i,0,n) cin>>a[i];
    dp[0][0] = 1;
    rep(i,0,n){
        dp[i+1][0] = dp[i][0];
        dp[i+1][1] = dp[i][1];
        
        if (a[i]%2==0){
            dp[i+1][0] += dp[i][0];
            dp[i+1][1] += dp[i][1];
        }else{
            dp[i+1][1] += dp[i][0];
            dp[i+1][0] += dp[i][1];
        }
    }
    cout<<dp[n][p]<<endl;
}