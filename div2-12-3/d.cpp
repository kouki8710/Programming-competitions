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
    int n,m;cin>>n>>m;
    vector<ll> dp(n+1),broke(n+1);
    rep(i,0,m){
        int a;cin>>a;
        broke[a] = 1;
    }
    dp[0] = 1;
    rep(i,0,n){
        if (i+1>n){
            continue;
        }

        if (broke[i+1]==0){
            dp[i+1] = (dp[i+1]+dp[i])%mod;
        }
        if (broke[i+2]==0){
            dp[i+2] = (dp[i+2] + dp[i]) % mod;
        }
    }
    cout<<dp[n]%mod<<endl;
}