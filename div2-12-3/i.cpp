#define _GLIBCXX_DEBUG
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
int dp[100][10000][100] = {0};


int main() {
    int n,a;cin>>n>>a;
    vector<ll> x(n);
    rep(i,0,n) cin>>x[i];
    dp[0][0][0] = 1;
    rep(i,0,n){
        rep(j,0,a*n+1){
            rep(k,0,n+1){
                dp[i+1][j][k] += dp[i][j][k];
                if (j-x[i]>=0 && k-1>=0){
                    dp[i+1][j][k] += dp[i][j-x[i]][k-1];
                }
            }
        }
    }
    ll ans = 0;
    rep(i,1,a+1){
        ans += dp[n][n*a][a];
    }
    cout<<ans<<endl;
}