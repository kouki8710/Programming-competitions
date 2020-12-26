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
    int n;cin>>n;
    vector<vector<ll>> dp(n+1 ,vector<ll>(3));
    rep(i,0,n){
        ll a,b,c;cin>>a>>b>>c;
        rep(j,0,3){
            dp[i+1][0] = max(dp[i][1]+b,dp[i][2]+c);
            dp[i+1][1] = max(dp[i][0]+a,dp[i][2]+c);
            dp[i+1][2] = max(dp[i][0]+a,dp[i][1]+b);
        }
    }
    cout<< *max_element(dp[n].begin(), dp[n].end()) <<endl;
}