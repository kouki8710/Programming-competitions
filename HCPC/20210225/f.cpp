#define _GLIBCXX_DEBUG
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
typedef pair<pair<ll,ll>,ll> PPL;
typedef tuple<int,int,int> T;
typedef tuple<ll,ll,ll> TL;
ll mod = 1000000007;
ll mod2 = 998244353;
ll n,m;

void dfs(int v, int p, vector<vector<ll>> &G, vector<vector<ll>> &dp) {  // 頂点v, 親p
    int deg = G[v].size();     // 頂点vの次数
    if (deg == 0) {          // 末端にいる時
        return;
    }
    vector<ll> num(deg);
    for (ll u : G[v]) {      // u: vの子
        if (u == p) continue;        // 親なら探索しない
        dfs(u, v, G, dp);               // dp[u] の計算
    }
    rep(i,1,m+1){
        dp[v][i] += dp[v][i-1];
        ll max_num = 0;
        ll max_ind = -1;
        rep(j,0,deg){
            ll u = G[v][j];
            if (num[j]+1 <= m && max_num < dp[u][num[j]+1]-dp[u][num[j]]){
                max_num = dp[u][num[j]+1]-dp[u][num[j]];
                max_ind = j;
            }
        }
        if (max_ind!=-1){
            ll u = G[v][max_ind];
            dp[v][i] += max_num;
            num[max_ind]++;
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    vector<vector<ll>> G(n), dp(n,vector<ll>(m+1));
    vector<ll> yaruki(n);
    ll boss = 0;
    rep(i,0,n){
        ll s,a;cin>>s>>a;
        yaruki[i] = a;
        if (s==0){
            boss = i;
            continue;
        }
        s--;
        G[s].push_back(i);
    }

    rep(i,0,n){
        dp[i][1] = yaruki[i];
    }

    dfs(boss, -1, G, dp);
    cout<<dp[0][m]<<endl;
}