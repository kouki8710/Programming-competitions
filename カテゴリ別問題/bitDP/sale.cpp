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
    int v,e;cin>>v>>e;
    int G[v][v];

    rep(i,0,v){
        rep(j,0,v){
            G[i][j] = INF;
        }
    }

    rep(i,0,e){
        int s,t,d;cin>>s>>t>>d;
        G[s][t] = d;
    }

    int m = 1 << v;
    int dp[m][v] = {0};
    rep(i,0,m){
        rep(j,0,v){
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;

    rep(s,0,m){
        rep(j,0,v){
            rep(k,0,v){

                // jを既に通っているか。 2度通ってはいけない
                if ( s & (1<<j) ) continue; 

                // sにkが含まれているか 更新は既に通った頂点から 0は何処も通っていない -> 全てから更新可能
                if ( s!=0 && !(s & (1<<k)) ) continue; 

                // 辺がないと更新不可
                if (G[k][j]==INF) continue;
                
                // 更新
                dp[s | (1<<j)][j] = min(dp[s | (1<<j)][j], dp[s][k] + G[k][j]);
            }
        }
    }

    if (dp[m-1][0]!=INF){
        cout<<dp[m-1][0]<<endl;
    }else{
        cout<<-1<<endl;
    }
    
}