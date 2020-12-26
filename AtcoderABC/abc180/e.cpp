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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;cin>>n;
    vector<ll> x(n),y(n),z(n);
    rep(i,0,n){
        cin>>x[i]>>y[i]>>z[i];
    }

    ll m = 1<<n;
    vector<vector<ll>> dp(m,vector<ll>(n));
    rep(i,0,m){
        rep(j,0,n){
            dp[i][j] = INF;
        }
    }

    dp[0][0] = 0;

    rep(s,0,m){
        rep(j,0,n){
            rep(k,0,n){
                
                if (s & (1<<j)) continue;

                if (s!=0 && !(s & (1<<k)) ) continue;

                ll cost = abs(x[j]-x[k]) + abs(y[j]-y[k]) + max(0LL, z[j]-z[k]);
                dp[s | (1<<j)][j] = min(dp[s | (1<<j)][j], dp[s][k]+cost);
            }
        }
    }

    cout<<dp[m-1][0]<<endl;
}